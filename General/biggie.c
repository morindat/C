# include <stdio.h>
# include <math.h>


// Function to calculate powers
int power (int a, int b){
    if (b == 0){
        return 1;
    }
    else {
        return a * power (a, b-1);
    }
}

// Function to evaluate polynomial
float polynomial (int x, float coeff[], int k){
    float fun = 0;
    for (int i = 0; i <= k; i ++){
        float term = coeff[i] * power (x, i);
        fun += term;
    }
    return fun;
}

// function to print the polynomial
void print_polynomial(float coeff[], int k) {
    printf("The polynomial is: ");
    int firstTermPrinted = 0; // Flag to track if the first non-zero term has been printed

    for (int i = k; i >= 0; i--) {
        if (coeff[i] != 0) { // Only process non-zero coefficients
            if (firstTermPrinted) {
                printf(" + "); // Add "+" only after the first term
            }

            // Print the coefficient if it's not 1 or if it's the constant term
            if (coeff[i] != 1 || i == 0) {
                printf("%.2f", coeff[i]);
            }

            // Print "x" for non-constant terms
            if (i > 0) {
                printf("x");
            }

            // Print the exponent for powers greater than 1
            if (i > 1) {
                printf("^%d", i);
            }

            firstTermPrinted = 1; // Mark that the first term has been printed
        }
    }

    printf("\n");
}

int main(){
    // get the value k
    int k;
    printf("Please enter the the degree of polynomial: ");
    scanf("%d", &k);

    // get the coeff of the polynomial
    float coeff[k + 1];
    printf("Please enter the coefficients of the polynomial: \n");
    for (int i = 0; i <= k; i ++){
        printf("a_%d: ", i);
        scanf("%f", &coeff[i]);
    }

    // print the polynomial
    print_polynomial(coeff, k);

    // get the value c, must be twice as big as the value of coeff at position k + the degree of polynomial k
    float c;
    printf("Enter the positive constant c (%0.3f < c): ", fabs(coeff[k]) + k);
    scanf("%f", &c);

    printf("\n");
    printf("x\t  %10s  %14s\t %5.1f%6s\n", "|f(x)|", "|g(x)|", c, "|g(x)|");
    printf("----------------------------------------------------\n");

    for (int x = 0; ; x ++){
        double function1 = polynomial(x, coeff, k);
        double function2 = power(x, k);

        printf("%d\t %10.2f\t %10.2f\t %10.2f\n", x, fabs(function1), fabs(function2), c * fabs(function2));

        if (fabs(function1) < fabs(c * function2)) {
            printf("---------------------------------------------------\n");
            printf("The required n_0 is: %d\n", x);
            break;
        }
    }

    return 0;
}