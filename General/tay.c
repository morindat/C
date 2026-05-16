# include <stdio.h>
# include <math.h>

double factorial (int n){
    double fact = 1.0;
    if (n == 0 || n == 1){
        return fact;
    }
    else{
        for (int i = 2; i <= n; i++){
            fact *= i;
        }
    }
    return fact;
}

int main (){
    double approx, real;
    double c;
    double x;

    printf("Please enter the value x: ");
    scanf("%lf", &x);

    printf("Please enter the value c: ");
    scanf("%lf", &c);

    real = exp(x);
    approx = 1 + x;
    int n = 2;

    while(fabs(real - approx) >= c){
        approx += pow(x, n) / factorial (n);
        n ++;
    }

    printf("The real value is: %lf\n", real);
    printf("The approximated value is: %lf\n", approx);
    printf("The number of iterations taken: %d", n);

    return 0;
}