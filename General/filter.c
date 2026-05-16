#include <stdio.h>

// Simple prime checker
int isPrime(int n) {
    if (n < 2) return 0; // Less than 2 isn’t prime
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0; // Divisible, not prime
    }
    return 1; // No divisors, prime
}

// Main program
int main() {
    int arr[] = {4, 7, 10, 13, 15, 17, 19, 20, 23};
    int size = sizeof(arr) / sizeof(arr[0]);
    int primes[size], primeCount = 0;

    // Filter primes
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            primes[primeCount++] = arr[i];
        }
    }

    // Print results
    printf("Original: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\nPrimes (%d): ", primeCount);
    for (int i = 0; i < primeCount; i++) printf("%d ", primes[i]);
    printf("\n");

    return 0;
}