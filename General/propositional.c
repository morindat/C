# include <stdio.h>

int main (){
    int A, B, C, X, Y, Z;

    printf("Please enter A: ");
    scanf("%d", &A);

    printf("Please enter B: ");
    scanf("%d", &B);

    if (A == 1 && B == 1){
        X = 1;
    }
    else{
        X = 0;
    }

    printf("Please enter C: ");
    scanf("%d", &C);

    if (C == 1){
        Y = 0;
    }
    else{
        Y = 1;
    }

    if (X || Y == 1){
        Z = 1;
    }
    else{
        Z = 0;
    }
    printf("The expression evaluates to: %d\n", Z);



    int a, b, c, result;

    // Input values
    printf("Please enter A (0 or 1): ");
    scanf("%d", &a);

    printf("Please enter B (0 or 1): ");
    scanf("%d", &b);

    printf("Please enter C (0 or 1): ");
    scanf("%d", &c);

    // Evaluate the logical expression
    result = (a && b) || !c;

    // Output the result
    printf("The expression evaluates to: %d\n", result);



    return 0;
}