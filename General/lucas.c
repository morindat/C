#include <stdio.h>

// Recursive function to compute the nth Lucas number
int lucas(int n) {
    if (n == 0) return 2; // Base case: L(0) = 2
    if (n == 1) return 1; // Base case: L(1) = 1
    return lucas(n - 1) + lucas(n - 2); // Recursive case
}

// Function to print the Lucas sequence up to n terms
void printLucasSequence(int n) {
    printf("Lucas sequence up to %d terms:\n", n);
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lucas(i)); // Compute and print each term
    }
    printf("]\n");
    //printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    // Print the Lucas sequence
    printLucasSequence(n);

    return 0;
}