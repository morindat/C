#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* right;
    struct Node* left;
} Node;

// Function to check if there's a root-to-leaf path with a given sum
bool hasPath(Node* root, int target) {
    if (root == NULL) return false;

    // If leaf node, check if target matches node's value
    if (root->left == NULL && root->right == NULL) {
        return (target == root->val);
    }

    // Otherwise, check left and right subtrees
    return hasPath(root->left, target - root->val) ||
           hasPath(root->right, target - root->val);
}

// Helper function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    /*
        Construct the following binary tree:

                5
               / \
              4   8
             /   / \
            11  13  4
           /  \      \
          7    2      1

        Example paths and sums:
        5 → 4 → 11 → 2 = 22  ✅
        5 → 8 → 4 → 1  = 18  ❌ (not 22)
    */

    Node* root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(8);
    root->left->left = createNode(11);
    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);
    root->right->left = createNode(13);
    root->right->right = createNode(4);
    root->right->right->right = createNode(1);

    int target = 22;
    if (hasPath(root, target))
        printf("Tree has a root-to-leaf path with sum %d\n", target);
    else
        printf("No root-to-leaf path with sum %d\n", target);

    // Free memory
    free(root->right->right->right);
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left->left->right);
    free(root->left->left->left);
    free(root->left->left);
    free(root->left);
    free(root);

    return 0;
}