# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *front;
    Node *rear;
} Queue;

Node *createNode(int val){
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

Queue *createQueue(){
    Queue *q = malloc(sizeof(Queue));

    if (!q){
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    q->front = q->rear = NULL;

    return q;
}

void enque(Queue *q, int val){
    Node *newNode = malloc(sizeof(Node));
    if (!newNode){
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL){
        q->rear = q->front = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

/*
void enqueueFront(Queue *q, int val){
    Node *newNode = malloc(sizeof(Node));
    if (!newNode){
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->next = q->front;
    q->front = newNode;

    if (q->rear == NULL){
        q->rear = newNode;
    }

}
*/

int dequeue(Queue *q){
    if (q->front == NULL){
        printf("Empty queue");
        return -1;
    }

    Node *temp = q->front;
    int popped = temp->data;

    q->front = q->front->next;

    if (q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    return popped;
}

void push(Node **top, int val){
    Node *newNode = createNode(val);
    newNode->next = *top;
    *top = newNode;
}

int pop(Node **top){
    if (*top == NULL) return -1;

    Node *temp = *top;
    int val = temp->data;

    *top = temp->next;
    free(temp);

    return val;

}

void freeQueue(Queue *q){
    Node *current = q->front;
    while(current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    q->front = NULL;
    q->rear = NULL;
}

void print(Queue *q){
    if (q->front == NULL){
        printf("Empty Queue");
        return;
    }

    Node *temp = q->front;
    printf("Queue: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

}

void reverse(Queue *q, int k){
    if (q == NULL || q->front == NULL || k <= 0) return;

    Node *stack = NULL;

    // Remove from queue and push to stack
    for (int i = 0; i < k && q->front != NULL; i++){
        int val = dequeue(q);
        push(&stack, val);
    }

    // Pop from stack and enqueue to Queue
    while (stack != NULL) {
        int val = pop(&stack);
        enque(q, val);
    }

    // Rearrage them into correct order
    int size = 0;
    Node *temp = q->front;

    while (temp != NULL){
        size++;
        temp = temp->next;
    }

    for (int i = 0; i < size - k; i++){
        int val = dequeue(q);
        enque(q, val);
    }
}

int main(){
    Queue *q = createQueue();
    
    for (int i = 0; i < 6; i++){
        enque(q, i*10);
    }
    
    printf("Original Queue\n");
    print(q);

    int k = 3;
    reverse(q, k);

    printf("After reversing\n");
    print(q);

    freeQueue(q);
    free(q);

    return 0;
}