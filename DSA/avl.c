# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int height (Node *n){
    if (n == NULL){
        return 0;
    }
    return n->height;
}

int max (int a, int b){
    return (a > b) ? a : b;
}

Node *createNode (int data){
    Node* node = malloc(sizeof(Node));
    if (!node){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    node->key = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int getBalance (Node* n){
    if (n == NULL){
        return 0;
    }

    return height(n->left) - height(n->right);
}

Node* leftRotate(Node *y){
    Node* x = y->right;
    Node* t2 = x->left;

    // rotate
    x->left = y;
    y->right = t2;

    // updated heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* rightRotate(Node *y){
    Node* x = y->left;
    Node* t2 = x->right;

    // rotate
    x->right = y;
    y->left = t2;

    // updated heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* insert(Node* node, int key){
    // Insert normally
    if (node == NULL) return createNode(key);

    if (key < node->key){
        node->left = insert(node->left, key);
    } else if (key > node->key){
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    // Update height and get balance
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Case 1: LL imbalance
    if (balance > 1 && key < node->left->key){
        return rightRotate(node);
    }

    // Case 2: RR imbalance
    if (balance < -1 && key > node->right->key){
        return leftRotate(node);
    }

    // Case 3: LR imbalance
    if (balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: RL imbalance
    if (balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;

}

Node* mini(Node* node){
    Node* current = node;

    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

Node* delete(Node* root, int key){
    if (root == NULL) return root;

    // Step 1: BST deletion
    if (key < root->key){
        root->left = delete(root->left, key);
    } else if (key > root->key){
        root->right = delete(root->right, key); // <-- fixed semicolon
    } else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;

        // Case 2: One child
        } else if (root->left == NULL || root->right == NULL){
            Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;

        // Case 3: Two children
        } else {
            Node* temp = mini(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }
    
    // Step 2: Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Step 3: Get balance factor
    int balance = getBalance(root);

    // Step 4: Balance if unbalanced

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


void preOrder(Node *root){
    if (root == NULL){
        return;
    } 

    printf("%d -> ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Node *root = NULL;

    // Example: Insert sequence
    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        root = insert(root, keys[i]);
    }

    printf("Preorder traversal of AVL tree:\n");
    preOrder(root);
    printf("NULL");
    printf("\n");
    delete(root, 10);
    printf("Preorder traversal of AVL tree:\n");
    preOrder(root);
    printf("NULL");
    printf("\n");

    return 0;
}
