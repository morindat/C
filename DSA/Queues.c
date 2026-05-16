# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue(){
    Queue *q = malloc(sizeof(Queue));
    if (!q){
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;

    return q;
}

void Enqueue(Queue *q, int val){
    Node *newNode = malloc (sizeof(Node));

    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL){
        q->front = q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int Dequeue(Queue *q){
    if (q->front == NULL){
        printf("Empty Queue");
        return -1;
    }

    Node *temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL){
        q->rear = NULL;
    }

    free(temp);

    return value;
}

int peek(Queue *q){
    if (q == NULL){
        printf("Empty Queue");
        return -1;
    }

    return q->front->data;
}

int isEmpty(Queue *q){
    return q->front == NULL;
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

int main() {
    Queue *q = createQueue();

    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);

    print(q);  

    printf("Dequeued: %d\n", Dequeue(q)); 
    print(q);  

    printf("Peek: %d\n", peek(q)); 

    Enqueue(q, 40);
    Enqueue(q, 50);
    print(q);  

    while (!isEmpty(q)) {
        printf("Dequeued: %d\n", Dequeue(q));
    }

    print(q); // Should print "Empty Queue"

    freeQueue(q);
    free(q); // Free the queue structure itself

    return 0;
}