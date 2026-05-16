# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode (int data){
    Node* node = malloc(sizeof(Node));
    node->val = data;
    node->right = NULL;
    node->left = NULL;

    return node;
}

Node* insert(Node* root, int key){
    if (root == NULL) return createNode(key);

    Node* temp = root;

    while(1){
        if (key < temp->val){
            if (temp->left == NULL){
                temp->left = createNode(key);
                break;
            }
            temp = temp->left;
        } else if (key > temp->val){
            if (temp->right == NULL){
                temp->right = createNode(key);
                break;
            }
            temp = temp->right;
        } else {
            break;
        }
    }
    
    return root;
}

int checkHeight(Node* root){
    if (root == NULL) return 0;

    int left = checkHeight(root->left);
    int right = checkHeight(root->right);

    if (left == -1 || right == -1){
        return -1;
    }

    if (abs(left - right) > 1){
        return -1;
    }

    return (left > right ? left : right) + 1;

}

int isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

void inorder(Node* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}


void freeTree(Node* root){
    if (root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}


int main (){
    Node* root = NULL;

    int arr[] = {10, 7, 15, 6, 8, 11, 17, 9, 21, 23, 31};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < size; i++){
        root = insert(root, arr[i]);
    }


    printf("BST: ");
    inorder(root);
    printf("\n\n");

    if (isBalanced(root))
        printf("Tree is balanced.\n");
    else
        printf("Tree is NOT balanced.\n");

    freeTree(root);
    return 0;
}