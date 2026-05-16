# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define MAX 100

typedef struct {
    int top;
    int arr[MAX];
} Stack;

// Initializing

void init(Stack* s){
    s->top = -1;
}

// Utilities

bool isEmpty(Stack* s){
    return s->top == -1;
}

bool isFull(Stack* s){
    return s->top == MAX - 1;
}

int peek (Stack* s){
    if (isEmpty(s)){
        printf("Nothing here\n");
        return 1;
    }

    return s->arr[s->top];
}

// Push

void push(Stack* s, int val){
    if (isFull(s)){
        printf ("Full, can not push\n");
        return;
    }

    s->arr[++(s->top)] = val;
}

// Pop

int pop(Stack* s){
    if (isEmpty(s)){
        printf("Empty, can not pop\n");
        return 1;
    }

    int val = s->arr[(s->top)--];
    
    return val;
}

// printing

void printArr(Stack* s){
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    printf("STACK: [ ");

    for (int i = 0; i <= s->top; i++){
        printf("%d ", s->arr[i]);
    }

    printf("]\n");
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

    printArr(&s);
    printf ("Poped: %d\n", pop(&s));
    printArr(&s);
    
    printf("Is stack empty? %s", isEmpty(&s)? "true" : "false");

    return 0;
}