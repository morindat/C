# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int val;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

// Utility functions
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node){
        printf("Memory allocation failed\n");
        return NULL;
    }
    node->val = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;   // new node is initially at height 1

    return node;
}


int height(Node* node){
    if (node == NULL) return 0;

    return node->height; // stored in the struct
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int getBalance (Node* node){
    if (node == NULL) return 0;

    return height(node->left) - height(node->right);
}

Node* findMin(Node* root){
    while(root && root->left){
        root = root->left;
    }

    return root;
}

/*        
            SUMMARY OF UTILITIES FUNCTIONS
| Function       | Purpose                               |
| -------------- | ------------------------------------- |
| `height()`     | Safely return node height (0 if NULL) |
| `max()`        | Returns larger of two integers        |
| `getBalance()` | Compute balance factor                |
| `newNode()`    | Create and initialize a new node      |

*/

// Rotations

Node* rotateRight(Node* unbalanced){
    // Store the left subtrees so we do not lose them and the right child of the new root
    Node* newRoot = unbalanced->left;
    Node* unbalancedLeftChild = newRoot->right;

    // Rotate
    newRoot->right = unbalanced;
    unbalanced->left = unbalancedLeftChild;

    // Update heights
    unbalanced->height = 1 + max(height(unbalanced->left), height(unbalanced->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

    return newRoot;
}

Node* rotateLeft(Node* unbalanced){
    Node* newRoot = unbalanced->right;
    Node* unbalancedRightChild = newRoot->left;

    newRoot->left = unbalanced;
    unbalanced->right = unbalancedRightChild;

    // Update heights
    unbalanced->height = 1 + max(height(unbalanced->left), height(unbalanced->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

    return newRoot;
}

Node* rotateLeftRight(Node* unbalanced) {
    unbalanced->left = rotateLeft(unbalanced->left);   // Step 1: fix inner imbalance
    return rotateRight(unbalanced);           // Step 2: fix outer imbalance
}

Node* rotateRightLeft(Node* unbalanced) {
    unbalanced->right = rotateRight(unbalanced->right);  // Step 1
    return rotateLeft(unbalanced);              // Step 2
}


Node* insert(Node* root, int key){
    // Step 1: Normal BST insertion

    if (root == NULL) return createNode(key);

    if (key < root->val){
        root->left = insert(root->left, key);
    }

    else if (key > root->val){
        root->right = insert(root->right, key);
    }

    else {
        return root;
    }

    // Step 2: Update Height and get balance factors

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Step 3: Check for imbalances and fix them if any

    // Case 1: LL imbalance
    if (balance > 1 && key < root->left->val){
        return rotateRight(root);
    }

    // Case 2: RR imbalance
    if (balance < -1 && key > root->right->val){
        return rotateLeft(root);
    }

    // Case 3: LR imbalance
    if (balance > 1 && key > root->left->val){
        return rotateLeftRight(root);
    }

    // Case 4: RL imbalance
    if (balance < -1 && key < root->right->val){
        return rotateRightLeft(root);
    }

    // Step 4: Return the root

    return root;
}

Node* delete(Node* root, int key) {
    // Step 1: Normal BST deletion
    if (root == NULL) return NULL;

    if (key < root->val) {
        root->left = delete(root->left, key);
    } 
    else if (key > root->val) {
        root->right = delete(root->right, key);
    } 
    else {
        // Node to be deleted found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }

        // Case 3: Two children
        Node* succ = findMin(root->right);
        root->val = succ->val;
        root->right = delete(root->right, succ->val);
    }

    // Step 2: Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Step 3: Rebalance
    int balance = getBalance(root);

    // Left heavy
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // Left-Right
    if (balance > 1 && getBalance(root->left) < 0)
        return rotateLeftRight(root);

    // Right heavy
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // Right-Left
    if (balance < -1 && getBalance(root->right) > 0)
        return rotateRightLeft(root);

    return root;
}

// Inorder traversal (LNR)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Level-order (BFS) traversal
void levelOrder(Node* root) {
    if (root == NULL) return;

    Node** queue = (Node**)malloc(1000 * sizeof(Node*));  // simple fixed-size queue
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelCount = rear - front;  // nodes in current level

        for (int i = 0; i < levelCount; i++) {
            Node* curr = queue[front++];
            printf("%d ", curr->val);

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        printf("\n");  // new line for each level
    }

    free(queue);
}

// Free entire tree
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// MAIN TEST
int main() {
    Node* root = NULL;

    // Insert nodes
    int values[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder traversal (sorted): ");
    inorder(root);
    printf("\n\nLevel order traversal (by levels):\n");
    levelOrder(root);

    // Delete a few nodes
    printf("\nDeleting 40...\n");
    root = delete(root, 40);

    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n\nLevel order after deletion:\n");
    levelOrder(root);

    // Cleanup
    freeTree(root);
    return 0;
}
