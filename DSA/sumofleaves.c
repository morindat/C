#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int val;
    struct Node* right;
    struct Node* left;
} Node;

bool isLeaf(Node* root){
    if (root == NULL) return false;
    if (root->right == NULL && root->left == NULL) return true;
    return false;
}

int sumOfLeftLeaves(Node* root){
    if (root == NULL) return 0;
    int sum = 0;

    if (root->left && isLeaf(root->left)){
        sum += root->left->val;
    }

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

// Helper function to create a new node
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    /*
        Construct the following binary tree:
        
                3
               / \
              9  20
                 /  \
                15   7

        Left leaves: 9 and 15 → sum = 24
    */

    Node* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    printf("Sum of left leaves: %d\n", sumOfLeftLeaves(root));

    // Free allocated memory
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}
