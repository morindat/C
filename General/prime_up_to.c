#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int n, i, p;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    bool isPrime[n + 1];

    // Initialize all numbers as prime
    for (i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    // 0 and 1 are not prime numbers
    isPrime[0] = isPrime[1] = false;

    for (p = 2; p <= sqrt(n); p++) {
        if (isPrime[p] == true) {
            // Marking multiples of p as not prime
            for (i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Printing all prime numbers
    printf("Prime numbers up to %d are: ", n);
    for (i = 2; i <= n; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
