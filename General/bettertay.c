#include <stdio.h>
#include <math.h>

int main() {
    double approx = 0.0, real;
    double c, x;

    printf("Please enter the value of x: ");
    scanf("%lf", &x);

    printf("Please enter the tolerance (c): ");
    scanf("%lf", &c);

    if (c <= 0) {
        printf("Error: Tolerance (c) must be positive.\n");
        return 1;
    }

    real = exp(x);

    double term = 1.0; // First term (n = 0)
    approx = term;
    int n = 0;     

    // Approximate e^x using the Taylor series
    int max_iterations = 10000; // Prevent infinite loops
    while (fabs(real - approx) >= c && n < max_iterations) {
        n++;
        term *= x / n; // Update the term iteratively
        approx += term;
    }

    // Check if the maximum iterations were reached
    if (n == max_iterations) {
        printf("Warning: Maximum iterations reached. Approximation may not be accurate.\n");
    }

    // Output results
    printf("The real value of e^%.2lf is: %.10lf\n", x, real);
    printf("The approximated value is: %.10lf\n", approx);
    printf("The number of terms used: %d\n", n);

    return 0;
}