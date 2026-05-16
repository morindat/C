#include <stdio.h>

int main() {
    // Sum of the first n numbers
    int n, i, sum;
    sum = 0;

    printf("Please enter a number: \n");
    scanf("%d", &n);

    if (n == 0) {
        printf("The number should be greater than 0\n");
    } else {
        for (i = 1; i <= n; i++) {
            sum += i;
        }
        printf("The sum of the first %d numbers is: %d\n", n, sum);
    }

    // Factorial of a number
    int num, x;
    unsigned long long factorial;
    factorial = 1;

    printf("Please enter a number: \n");
    scanf("%d", &num);

    if (num < 0) {
        printf("There are no factorials for negative numbers.\n");
    } else if (num == 0) {
        printf("The factorial of 0 is: 1\n");
    } else {
        for (x = 1; x <= num; x++) {
            factorial *= x;
        }
        printf("The factorial of %d is: %llu\n", num, factorial);
    }

    // Multiples of a number
    int multiples, number;
    multiples = 0;
    printf("Please enter a number: ");
    scanf("%d", &number);

    if (number <= 1) {
        printf("The number must be greater than 1\n");
    } else {
        printf("The multiples of %d are: ", number);
        while (multiples + number <= 200) {
            multiples += number;
            printf("%d ", multiples);
        }
        printf("\n");
    }

    return 0;
}