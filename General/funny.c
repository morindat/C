#include <stdio.h>

int addNumbers(int a, int b)
{ /* Function definition: adds two numbers a, b and returns a + b */
    return a + b;
}

int exponentiateNumbers(int a, int b)
{ /* Function definition: exponentiate two numbers a, b and returns a^b */
    int result = 1;
    for(int i = 0; i < b; i++)
    {
        result *= a;
    }

    return result;
}

int main() {
    int num1, num2;
    int sum, expo;

    printf("\n");
    printf("Enter two numbers (separated by a space): "); //............takes input from the user
    scanf("%d %d", &num1, &num2);

    sum = addNumbers(num1, num2); //.............the function call to add
    expo = exponentiateNumbers(num1, num2); //...the function call to exponentiate
    
    printf("\n");
    printf("Sum: %d\n", sum);
    printf("Power: %d\n", expo);
    printf("\n");

    return 0;
}