# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* right;
    struct Node* left;
} Node;

// The idea is, we need a way to find a root of the tree for which its left and right subtrees will be almost balanced
// Since the arr is already sorted, this makes the mid element of the array a suitable candidate
// This is because the no of elements before mid and after mid will be roughly the same
// So, have a helper function that will do the following
// 1. Find the mid index of the give array
// 2. Store the value at mid at some node, node
// 3. node.left = all values before mid (recursive call btw)
// 4. node.right = all values after mid
// return node (root of the tree)
// Base case: if left > right return null
// In the main function, call the helper function with the array and size of the array

Node* buildBST(int* nums, int left, int right){

    if (left > right) return NULL;

    int mid = left + (right - left) / 2;
    Node* node = malloc(sizeof(Node));
    node->val = nums[mid];
    node->left = buildBST(nums, left, mid-1);
    node->right = buildBST(nums, mid+1, right);

    return node;
}

Node* sortedArrayToBST(int* nums, int size){
    return buildBST(nums, 0, size-1);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void freeTree(Node* root){
    if (root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    int nums[] = {-10, -3, 0, 5, 9};
    int size = sizeof(nums)/sizeof(nums[0]);
    
    Node* root = sortedArrayToBST(nums, size);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}