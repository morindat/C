# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *createNode(int val){
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)return NULL;

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

Node *push(Node *top, int val){
    Node *newNode = createNode(val);
    newNode->next = top;

    return newNode;
}

Node *pop(Node *top, int *popped){
    if (top == NULL){
        printf("Can not pop");
    }

    *popped = top->data;
    Node *temp = top;
    top = top->next;
    free(temp);

    return top;
}

int peek(Node* top) {
    if (top == NULL) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1; // Sentinel value
    }
    return top->data;
}

int isEmpty(Node* top) {
    return top == NULL;
}

void print(Node *top){
    if (top == NULL){
        printf("Stack is empty");
        return;
    }

    printf("Stack (Top->Bottom): ");
    Node *temp = top;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freestack(Node *top){
    Node *temp;
    while(temp != NULL){
        temp = top;
        top->next;
        free(top);
    }
}


int main() {
    Node* top = NULL;

    // Push elements
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    print(top); // 30 → 20 → 10

    // Peek
    printf("Top element: %d\n", peek(top));

    // Pop
    int popped;
    top = pop(top, &popped);
    printf("Popped element: %d\n", popped);
    print(top); // 20 → 10

    // Check if empty
    printf("Stack is %sempty.\n", isEmpty(top) ? "" : "not ");

    // Free memory
    freestack(top);
    top = NULL;

    return 0;
}