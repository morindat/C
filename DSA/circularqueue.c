# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct CircularQ{
    Node *front;
    Node *rear;
} CircularQ;

Node *createNode(int val){
    Node *newNode = malloc (sizeof(Node));
    if (newNode == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

CircularQ *createQ(){
    CircularQ *q = malloc (sizeof(CircularQ));
    if (q == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    q->front = q->rear = NULL;

    return q;
}

CircularQ *enqueue(CircularQ *q, int val){
    Node *newNode = createNode(val);

    if (q->rear == NULL){
        q->rear = q->front = newNode;
        newNode->next = newNode; // Points to itself to maintain the circle
    }

    else{
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    }
}

int dequeue(CircularQ *q){
    if (q->front == NULL){
        printf("The queue is empty\n");
        return -1;
    }

    int val;

    if (q->front == q->rear){
        val = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    }
    else{
        Node *temp = q->front;
        val = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }

    return val;
}

void print(CircularQ *q){
    if (q == NULL || q->front == NULL){
        printf("Empty Queue\n");
        return;
    }

    Node *temp = q->front;
    printf("Circular Queue: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != q->front);

    printf("(back to the front)\n");
}

void freeCircularQueue(CircularQ *q){
    if (q->front == NULL) return;

    Node *current = q->front;
    Node *nextnode;

    do {
        nextnode = current->next;
        free(current);
        current = nextnode;
    } while (current != q->front);

    q->front = q->rear = NULL;
    free(q);

}

int main(){
    CircularQ *q = createQ();
    print(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    print(q);

    printf("Dequeued: %d \n", dequeue(q));
    dequeue(q);
    print(q);

    freeCircularQueue(q);
    free(q);
    q == NULL;

    return 0;
}