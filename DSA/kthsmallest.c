# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* right;
    struct Node* left;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root, int k, int *count, int *res){
    if (root == NULL || *count >= k) return;

    inorder(root->left, k, count, res);
    (*count)++;
    if (*count == k){
        *res = root->data;
        return;
    }
    inorder(root->right, k, count, res);
}

int kthSmallest(Node* root, int k) {
    int res = -1;
    int count = 0;
    inorder(root, k, &count, &res);
    return res;
}

void freeTree(Node* root){
    if (root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    // Create a sample BST
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);

    int k = 3;
    int result = kthSmallest(root, k);

    printf("The %d-th smallest element in the BST is: %d\n", k, result);

    freeTree(root);
    return 0;
}