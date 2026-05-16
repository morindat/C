#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    char arr[MAX][MAX];  // stack of strings
} Stack;

// Initialize
void init(Stack* s) {
    s->top = -1;
}

// Check if empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push a string
void push(Stack* s, const char* str) {
    if (s->top == MAX - 1) {
        printf("Full, cannot push\n");
        return;
    }
    strcpy(s->arr[++(s->top)], str);
}

// Pop a string
char* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Empty, cannot pop\n");
        exit(EXIT_FAILURE);
    }
    return s->arr[(s->top)--];
}

// Convert prefix to postfix
void prefixToPostfix(const char* prefix, char* postfix) {
    Stack s;
    init(&s);
    int len = strlen(prefix);

    // Scan from right to left
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isspace(c)) continue;  // skip spaces

        if (isalnum(c)) {  // operand
            char op[2] = {c, '\0'};
            push(&s, op);
        } else {  // operator
            char* op1 = pop(&s);
            char* op2 = pop(&s);
            char expr[MAX];
            snprintf(expr, sizeof(expr), "%s%s%c", op1, op2, c);
            push(&s, expr);
        }
    }

    strcpy(postfix, pop(&s));
}

int main() {
    char prefix[MAX], postfix[MAX];

    printf("Enter prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);

    // Remove newline
    prefix[strcspn(prefix, "\n")] = '\0';

    prefixToPostfix(prefix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}