#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>  

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}


Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}


bool validate(Node* root, long long low, long long high) {
    if (root == NULL) return true;

    long long v = root->data;

    if (v <= low || v >= high)
        return false;

    return validate(root->left, low, v) && validate(root->right, v, high);
}

// Main BST validation function
bool isValidBST(Node* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}

void freeTree(Node* root){
    if (root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// --- MAIN FUNCTION TO TEST ---
int main() {
    Node* root = NULL;

    // Build a valid BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    if (isValidBST(root))
        printf("✅ The tree is a valid BST.\n");
    else
        printf("❌ The tree is NOT a valid BST.\n");

    // Example of invalid BST:
    Node* invalid = newNode(5);
    invalid->left = newNode(1);
    invalid->right = newNode(4);
    invalid->right->left = newNode(3);
    invalid->right->right = newNode(6);

    if (isValidBST(invalid))
        printf("✅ The second tree is a valid BST.\n");
    else
        printf("❌ The second tree is NOT a valid BST.\n");

    freeTree(root);
    freeTree(invalid);
    return 0;
}
