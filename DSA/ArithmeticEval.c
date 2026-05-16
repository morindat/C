# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

#define MAX 100

int precedence (char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOperator(int a, int b, char op){
    int res;
    switch (op){
        case '+' : res = a + b; break;
        case '-' : res = b - a; break;
        case '/' : res = b / a; break;
        case '*' : res = a * b; break;
        default : res = 0;
    }
    return res;
}

int evaluate(char* exp){
    char ops[MAX];
    int vals[MAX];
    int topOps = -1;
    int topVals = -1;

    for (int i = 0; exp[i] != '\0'; i++){
        char c = exp[i];

        if (isspace(c)) continue;

        if (isdigit(c)) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--; // step back since for-loop also increments i
            vals[++topVals] = num;
        } else {
            while (topOps != -1 && precedence(ops[topOps]) >= precedence(c)){
                int a = vals[topVals--];
                int b = vals[topVals--];
                char op = ops[topOps--];
                vals[++topVals] = applyOperator(a, b, op);
            }
            ops[++topOps] = c;
        }
    }
    
    while (topOps != -1){
        // pop the operator and apply it to the first two elements of vals stack
        char op = ops[topOps--];
        int a = vals[topVals--];
        int b  = vals[topVals--];
        vals[++topVals] = applyOperator(a, b, op);
    }

    return vals[topVals]; // at the end of this, there is only one element remaining in the stack and that is the sum
}


int main() {
    char expr1[] = "3+5*2-9";
    char expr2[] = "8/2+3*2";
    char expr3[] = "7-4/2+6";

    printf("%s = %d\n", expr1, evaluate(expr1)); // expect 4
    printf("%s = %d\n", expr2, evaluate(expr2)); // expect 10
    printf("%s = %d\n", expr3, evaluate(expr3)); // expect 11

    return 0;
}
