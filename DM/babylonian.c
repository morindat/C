#include <stdio.h>
#include <math.h>

double babylonian(double r, double c, double prev, int k, int *steps){
    double next = 0.5 * (prev + r / prev);

    if (fabs(sqrt(r) - next) <= c){
        *steps = k;
        return next;
    }

    return babylonian(r, c, next, k + 1, steps);
}

int main(){
    double r, c;

    printf("Enter r: ");
    scanf("%lf", &r);

    printf("Enter c (0<c<1): ");
    scanf("%lf", &c);

    int steps = 0;

    double result = babylonian(r, c, r/2.0, 1, &steps);

    printf("Approx sqrt: %lf\n", result);
    printf("k = %d\n", steps);

    return 0;
}