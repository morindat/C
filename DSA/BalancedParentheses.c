#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node{
    char data;
    struct Node *next;
} Node;

Node *createNode(int val){
    Node *newNode = malloc (sizeof(Node));
    if (newNode == NULL) return NULL;

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void push(Node **top, int val){
    Node *newNode = createNode(val);
    newNode->next = *top;
    *top = newNode;
}

char pop(Node **top){
    if (*top == NULL) return '\0';

    Node *temp = *top;

    char data = temp->data;
    *top = temp->next;
    free(temp);

    return data;
}

char peek(Node *top) {
    return top ? top->data : '\0';
}

bool isEmpty(Node *top) {
    return top == NULL;
}

void freeStack(Node *top) {
    while (top != NULL) {
        Node *temp = top;
        top = top->next;
        free(temp);
    }
}

bool matches (char open, char close){
    return (open == '(' && close == ')' || 
            open == '[' && close == ']' ||
            open == '{' && close == '}'
            );
}

bool isBalanced(const char *expr){
    Node *stack = NULL;

    for (size_t i = 0; i < strlen(expr); i++){
        char c = expr[i];

        if (c == '(' || c == '{' || c == '['){
            push(&stack, c);
        }
        else if(c == ')' || c == '}' || c == ']'){
            if (isEmpty(stack) || !matches(peek(stack), c)){
                freeStack(stack);
                return false;
            }
            pop(&stack);
        }
    }

    bool balanced = isEmpty(stack);
    freeStack(stack);

    return balanced;
}

int main() {
    const char *tests[] = {
        "()[]{}",    // true
        "(]",        // false
        "({[]})",    // true
        "({[})",     // false
        "((()))",    // true
        "))((",      // false
        "",          // true
        "()",       // true
        NULL
    };

    for (int i = 0; tests[i] != NULL; i++){
        printf ("%d : %s\n", i+1, isBalanced(tests[i]) ? "Balanced" : "Not balanced");
    }

    return 0;
}