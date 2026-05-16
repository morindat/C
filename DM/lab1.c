#include <stdio.h>

// Function Prototypes
void print_factors(long long n);
void print_sum_of_digits(long long n);
void count_digits(long long n);
void check_perfect_number(long long n);
void check_armstrong_number(long long n);
void reverse_digits(long long n);
long long power(int base, int exp); // Helper for Armstrong calculation

int main() {
    long long num;

    // Input
    printf("Enter a positive integer: ");
    if (scanf("%lld", &num) != 1 || num <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    // Execute all 6 tasks
    print_factors(num);
    print_sum_of_digits(num);
    count_digits(num);
    check_perfect_number(num);
    check_armstrong_number(num);
    reverse_digits(num);

    return 0;
}

// Task 1: Print factors
void print_factors(long long n) {
    printf("\n--- Task 1: Factors of %lld ---\n", n);
    printf("Factors: ");
    for (long long i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%lld ", i);
        }
    }
    printf("\n");
}

// Task 2: Sum of digits
void print_sum_of_digits(long long n) {
    printf("\n--- Task 2: Sum of Digits of %lld ---\n", n);
    long long temp = n;
    long long sum = 0;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    printf("Sum of digits: %lld\n", sum);
}

// Task 3: Count digits
void count_digits(long long n) {
    printf("\n--- Task 3: Count Digits of %lld ---\n", n);
    long long temp = n;
    int count = 0;
    if (n == 0) {
        count = 1;
    } else {
        while (temp > 0) {
            temp /= 10;
            count++;
        }
    }
    printf("Number of digits: %d\n", count);
}

// Task 4: Check Perfect Number
void check_perfect_number(long long n) {
    printf("\n--- Task 4: Perfect Number Check for %lld ---\n", n);
    long long sum_divisors = 0;
    // Proper divisors exclude the number itself, so loop up to n/2
    for (long long i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum_divisors += i;
        }
    }

    if (sum_divisors == n) {
        printf("%lld is a Perfect Number.\n", n);
    } else {
        printf("%lld is NOT a Perfect Number.\n", n);
    }
}

// Task 5: Check Armstrong Number
void check_armstrong_number(long long n) {
    printf("\n--- Task 5: Armstrong Number Check for %lld ---\n", n);
    long long temp = n;
    int num_digits = 0;
    long long sum_power = 0;

    // 1. Count digits first
    long long t = n;
    while (t > 0) {
        t /= 10;
        num_digits++;
    }

    // 2. Calculate sum of digits raised to power of num_digits
    while (temp > 0) {
        int digit = temp % 10;
        sum_power += power(digit, num_digits);
        temp /= 10;
    }

    if (sum_power == n) {
        printf("%lld is an Armstrong Number.\n", n);
    } else {
        printf("%lld is NOT an Armstrong Number.\n", n);
    }
}

// Task 6: Reverse Digits
void reverse_digits(long long n) {
    printf("\n--- Task 6: Reverse Digits of %lld ---\n", n);
    long long temp = n;
    long long reversed_num = 0;
    
    while (temp > 0) {
        int digit = temp % 10;
        reversed_num = reversed_num * 10 + digit;
        temp /= 10;
    }
    printf("Reversed number: %lld\n", reversed_num);
}

// Helper function for integer power (avoids math.h precision issues)
long long power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}