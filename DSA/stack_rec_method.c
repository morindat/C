# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct  Node {
    int data; 
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

// Initialization

void init(Stack* s){
    s->top = NULL;
}

// isEmpty?

bool isEmpty(Stack* s){
    return s->top == NULL;
}

// push
// create node and add node in push

Node* createNode(int val){
    Node* newNode = malloc(sizeof(Node));
    if (!newNode){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void push(Stack* s, int val){
    Node* newNode = createNode(val);
    newNode->next = s->top;
    s->top = newNode;
}

// Pop

int pop(Stack* s){
    if (isEmpty(s)){
        printf("Stack empty can not pop\n");
        return 1;
    }

    Node* temp = s->top;
    int toDelete = temp->data;
    s->top = temp->next;
    free(temp);

    return toDelete;
}

// Printing

void print(Stack* s){
    if (isEmpty(s)){
        printf("Nothing to print\n");
        return;
    }

    Node* temp = s->top;
    printf("STACK: [");

    while (temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("]\n");
}

// freeing

void freeStack(Stack* s){
    Node* temp = s->top;

    while (temp){
        Node* curr = temp;
        temp = temp->next;
        free(curr);
    }

    s->top = NULL;
}

int peek(Stack* s){
    if (isEmpty(s)){
        printf("Nothing in the stack yet!");
        return 1;
    }

    return s->top->data;
}


int main(){
    Stack s;
    init(&s);
    peek(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);

    print(&s);
    printf ("Poped: %d\n", pop(&s));
    print(&s);
    
    printf("Is stack empty? %s\n", isEmpty(&s)? "true" : "false");
    

    freeStack(&s);
    //free(&s); is this not needed?
    print(&s); // nothing to print

    return 0;
}