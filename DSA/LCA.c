#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// Helper: Create a new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper: Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

// Function to find Lowest Common Ancestor
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == NULL) return NULL;

    int curr = root->val;

    if (curr < p->val && curr < q->val)
        return lowestCommonAncestor(root->right, p, q);

    if (curr > p->val && curr > q->val)
        return lowestCommonAncestor(root->left, p, q);

    return root; // this is the split point (LCA)
}

void freeTree(Node* root){
    if (root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;

    // Build BST
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 0);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 3);
    root = insert(root, 5);

    /*
              6
             / \
            2   8
           / \ / \
          0  4 7  9
            / \
           3   5
    */

    Node* p = root->left;  
    Node* q = root->left->right; 

    Node* ancestor = lowestCommonAncestor(root, p, q);
    if (ancestor)
        printf("Lowest Common Ancestor of %d and %d is: %d\n", p->val, q->val, ancestor->val);
    else
        printf("No common ancestor found.\n");

    freeTree(root);
    return 0;
}
