#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int val){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (!newNode){
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    newNode->data = val;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node* insertRec(Node* root, int val){
    // Ignore duplicates for now
    // Duplicates are allowed in the left subtree but that is less common

    if (root == NULL){
        Node* newNode = createNode(val);
        return newNode;
    }

    if (val < root->data){
        root->left = insertRec(root->left, val);
    }

    else if (val > root->data){
        root->right = insertRec(root->right, val);
    }

    return root;
}

Node* insertIte(Node* root, int val){
    if (root == NULL){
        return createNode(val);
    }

    Node* current = root;
    Node* prev = NULL;

    while (current){
        prev = current;

        if (val < current->data){
            current = current->left;
        }

        else if (val > current->data){
            current = current->right;
        }

        else {
            // duplicate
            // Ignore it

            return root;
        }
    }

    if (val < prev->data){
        prev->left = createNode(val);
    }
    else {
        prev->right = createNode(val);
    }

    return root;
}


Node* insertIteBetter(Node* root, int val){
    if (root == NULL) return createNode(val);

    Node* temp = root;

    while (1){
        if (val < temp->data){
            if (temp->left == NULL){
                temp->left = createNode(val);
                break;
            }
            temp = temp->left;
        }
        else if (val > temp->data){
            if (temp->right == NULL){
                temp->right = createNode(val);
                break;
            }
            temp = temp->right;
        }
        else {
            break;
        }
    }

    return root;
}

Node* searchRec (Node* root, int key){
    if (root == NULL) return NULL;

    if (root->data == key){
        return root;
    }

    if (key < root->data){
        return searchRec(root->left, key);
    }

    else if (key > root->data){
        return searchRec(root->right, key);
    }

    return NULL;

}

Node* searchIter (Node* root, int key){
    Node* temp = root;

    while (temp != NULL && temp->data != key){
        if (key < temp->data){
            temp = temp->left;
        }
        else if (key > temp->data){
            temp = temp->right;
        }
        // what if it is the root?
        // Loop exits immediately and returns temp
    }

    return temp;
}

// Traversal

void inorder (Node* root){
    // LDR: Left Data Right

    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root){
    // DLR

    if (root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder (Node* root){
    // LRD

    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void BFS(Node* root){
    if (root == NULL) return;
    Node* q[100];
    int front = 0;
    int rear = 0;
    q[rear++] = root;

    while(front < rear){
        Node* node = q[front++];
        printf("%d ", node->data);
        if (node->left) q[rear++] = node->left;
        if (node->right) q[rear++] = node->right;
    }
}

Node* findMin(Node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }

    return root;
}

Node* findMax (Node* root){
    while (root != NULL && root->right != NULL){
        root = root->right;
    }

    return root;
}

// Free the entire tree (post-order deletion)
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}


Node* deleteRBS(Node* root, int val){

    if (root == NULL) return NULL;

    if (val < root->data){
        root->left = deleteRBS(root->left, val);
    } else if (val > root->data){
        root->right = deleteRBS(root->right, val);
    } else {
        // Found the node to delete
        // There is 3 cases

        // 1: Node has no child, leaf node, just delete it

        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        // 2: Root has one child

        else if (root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // 3: Node has 2 children

        else {
            // This is Delete By In-order Sucessor
            // Means, replace root with the smallest value in right subtree

            Node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteRBS(root->right, successor->data);
        }
    }

    return root;

}

Node* deleteRBP (Node* root, int val){

    if (root == NULL) return NULL;

    if (val < root->data){
        root->left = deleteRBP(root->left, val);
    } else if (val > root->data){
        root->right = deleteRBP(root->right, val);
    } else {
        // Three conditions as always
        // 1. No child, just free it

        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        // 2. One child, either the left or right

        else if (root->left == NULL || root->right == NULL){
            Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }

        // 3. Both children present
        // In-order predecessor
        // The largers in left subtree

        else {
            Node* predecessor = findMax(root->left);
            root->data = predecessor->data;
            root->left = deleteRBP(root->left, predecessor->data);
        }
    }

    return root;
}

int height (Node* root){
    if (root == NULL){
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int max (int a, int b){
    return (a > b ? a : b);
}

int heightNodes (Node* root){
    if (root == NULL){
        return 0;
    }

    return 1 + max(heightNodes(root->left), heightNodes(root->right));
}

Node* successor(Node* root, Node* p){
    Node* succ = NULL;

    while (root != NULL){
        if (p->data >= root->data){
            root = root->right;
        } else {
            succ = root;
            root = root->left;
        }
    }

    return succ;
}

int main(){
    printf("=== BST IMPLEMENTATION TEST ===\n\n");

    // Test recursive insertion
    Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserting values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insertRec(root, values[i]);
    }
    printf("\n\n");

    printf("====HEIGHT TEST====\n\n");
    printf("Height by no of nodes: %d\n", heightNodes(root));
    printf("Height by height: %d\n\n", height(root));

    // Test traversals
    printf("=== TRAVERSALS ===\n");
    printf("In-order (sorted): ");
    inorder(root);
    printf("\n");

    printf("Pre-order: ");
    preorder(root);
    printf("\n");

    printf("Post-order: ");
    postorder(root);
    printf("\n\n");

    // Test search
    printf("=== SEARCH TESTS ===\n");
    int search_keys[] = {35, 100, 50, 10};
    for (int i = 0; i < 4; i++) {
        Node* found_rec = searchRec(root, search_keys[i]);
        Node* found_iter = searchIter(root, search_keys[i]);

        printf("Searching for %d:\n", search_keys[i]);
        if (found_rec) {
            printf("  Recursive: FOUND (%d)\n", found_rec->data);
        } else {
            printf("  Recursive: NOT FOUND\n");
        }

        if (found_iter) {
            printf("  Iterative: FOUND (%d)\n", found_iter->data);
        } else {
            printf("  Iterative: NOT FOUND\n");
        }
        printf("\n");
    }

    // Test min and max
    printf("=== MIN/MAX ===\n");
    Node* min_node = findMin(root);
    Node* max_node = findMax(root);

    if (min_node) {
        printf("Minimum value: %d\n", min_node->data);
    }
    if (max_node) {
        printf("Maximum value: %d\n", max_node->data);
    }
    printf("\n");

    // Test iterative insertion
    printf("=== ITERATIVE INSERT TEST ===\n");
    Node* root2 = NULL;
    root2 = insertIteBetter(root2, 25);
    root2 = insertIteBetter(root2, 15);
    root2 = insertIteBetter(root2, 25); // duplicate - should be ignored
    root2 = insertIteBetter(root2, 35);

    printf("Tree built with iterative insert (in-order): ");
    inorder(root2);
    printf("\n\n");

    // Test edge cases
    printf("=== EDGE CASES ===\n");
    Node* empty = NULL;
    printf("Search in empty tree (key=5): %s\n",
           searchIter(empty, 5) == NULL ? "NULL (correct)" : "ERROR");
    printf("Min of empty tree: %s\n",
           findMin(empty) == NULL ? "NULL (correct)" : "ERROR");
    printf("Max of empty tree: %s\n",
           findMax(empty) == NULL ? "NULL (correct)" : "ERROR");

    printf("\n=== CLEANING UP MEMORY ===\n");

    printf ("====TEST DELETE====\n\n");
    printf("Before deleteing 50: \n");
    inorder(root);
    printf("\n");
    root = deleteRBP(root, 50);
    printf("After deleting 50: \n");
    inorder(root);
    printf("\n");

    // Free all allocated memory
    freeTree(root);
    freeTree(root2);
    freeTree(empty); // Safe to call on NULL

    printf("All memory freed successfully!\n");
    printf("\n=== ALL TESTS COMPLETED SUCCESSFULLY! ===\n");

    return 0;
}
