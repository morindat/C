# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *front;
    Node *rear;
} Deque;

Deque *createDq(){
    Deque *dq = malloc (sizeof(Deque));
    if (!dq){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    dq->front = dq->rear = NULL;

    return dq;
}

Node *createNode(int val){
    Node *newNode = malloc (sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

Node *enqueueFront(Deque *dq, int val){
    if (dq == NULL) return NULL;

    Node *newNode = createNode(val);

    if (dq->front == NULL){
        dq->front = dq->rear = newNode;
    }
    else{
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }

    return newNode; // Now the front of the dq
}

Node *enqueueBack(Deque *dq, int val){
    if (dq == NULL) return NULL;

    Node *newnode = createNode(val);

    if (dq->front == NULL){
        dq->front = dq->rear = newnode;
    }
    else{
        dq->rear->next = newnode;
        newnode->prev = dq->rear;
        dq->rear = newnode;
    }

    return newnode;
}

int dequeueFront(Deque *dq){
    if (dq == NULL || dq->front == NULL){
        printf("Empty Deque\n");
        return -1;
    }

    Node *temp = dq->front;
    int val = temp->data;

    if (dq->front == dq->rear){
        dq->front = dq->rear = NULL;
    }
    else{
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    free(temp);
    return val;
}

int dequeueBack(Deque *dq){
    if (dq == NULL || dq->front == NULL){
        printf("Empty Deque\n");
        return -1;
    }

    Node *temp = dq->rear;
    int val = temp->data;

    if(dq->front == dq->rear){
        dq->front = dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }

    free(temp);
    return val;
}

void printDeque(Deque *dq) {
    if (dq == NULL || dq->front == NULL) {
        printf("Deque is empty\n");
        return;
    }

    Node *temp = dq->front;
    printf("Deque (front to rear): ");

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }

    printf("\n");
}

bool isPalindrome(Deque *dq){
    if (!dq || dq->front == NULL) return true;

    Node *left = dq->front;
    Node *right = dq->rear;

    while (left != right && left->prev != right){
        if(left->data != right->data){
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    return true;
}


int main() {
    Deque *dq = createDq();

    enqueueBack(dq, 10);
    enqueueBack(dq, 10);
    enqueueFront(dq, 20);
    enqueueBack(dq, 20);
    printDeque(dq);  
    printf("Palindrome?: %s\n", isPalindrome(dq) ? "Yes" : "No");

    dequeueFront(dq);  
    dequeueBack(dq); 
    printDeque(dq);    

    enqueueFront(dq, 1);
    printDeque(dq);    

    dequeueBack(dq);  
    dequeueFront(dq); 
    printDeque(dq);   

    dequeueFront(dq);  
    printDeque(dq);   

    return 0;
}