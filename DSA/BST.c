# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode (int data){
    Node *newnode = malloc(sizeof(Node));

    if (!newnode){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newnode->key = data;
    newnode->right = newnode->left = NULL;

    return newnode;
}

Node* insert(Node *root, int key){
    if (root == NULL) return createNode(key);

    if (key < root->key){
        root->left = insert(root->left, key);
    }

    else if (key > root->key){
        root->right = insert(root->right, key);
    }

    else{
        root->right = insert(root->right, key);
    }

    return root;
}

Node* search(Node* root, int key){
    if (root == NULL) return NULL;

    while (root != NULL && root->key != key){
        if (key < root->key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return root;
}

void inorder(Node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preoder(Node *root){
    if (root != NULL){
        printf("%d ", root->key);
        preoder(root->left);
        preoder(root->right);
    }
}

void postorder(Node *root){
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

Node *findMin(Node *root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }

    return root;
}

Node* findMax (Node *root){
    while (root != NULL && root->right != NULL){
        root = root->right;
    }

    return root;
}

Node *delete(Node *root, int key){
    if (root == NULL) return root;

    if (key < root->key){
        root->left = delete(root->left, key);
    } else if (key > root->key){
        root->right = delete(root->right, key);
    } 

    else {
        // Case 1: No child
        // That is the root is the only present node
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        // Case 2: One root only, either left or right
        if (root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Both childs present
        // With in-order successor
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }

    return root;
}

Node* deleted(Node* root, int key){
    if (root == NULL) return root;

    if (key < root->key){
        root->left = deleted(root->left, key);
    } else if (key > root->key){
        root->right = deleted(root->right, key);
    } else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        // Case two: One child
        if (root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        // With in-order predecessor
        Node *temp = findMax(root->left);
        root->key = temp->key;
        root->left = deleted(root->left, temp->key);
    }

    return root;

}

int main(){
    Node *root = NULL;

    root = insert(root, 8);
    root = insert(root, 11);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 23);
    root = insert(root, 14);
    deleted(root, 8);

    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    printf("Preorder: ");
    preoder(root);
    printf("\n");
    findMin(root);
    
    Node *min = findMin(root);
    Node *max = findMax(root);

    if (min != NULL){
        printf("Minimum: %d\n", min->key);
    } else{
        printf("Tree is empty!\n");
    }

    if (max != NULL){
        printf("Maximum: %d\n", max->key);
    } else{
        printf("Tree is empty!\n");
    }

    return 0;
}