# include <stdio.h>
# include <math.h>

int main (){
    double a, r, c;
    double real;
    double approx = 0.0;
    int n = 0;

    printf("Please enter the value a: ");
    scanf("%lf", &a);

    printf("Please enter the value r: ");
    scanf("%lf", &r);
    
    printf("Please enter the value c: ");
    scanf("%lf", &c);

    real = a / (1 - r);
    approx = a;
    n ++;

    while (fabs(real - approx) >= c){
        approx += a * pow(r, n);
        n ++;
    }

    printf("The real value is: %lf\n", real);
    printf("The approximated value is: %lf\n", approx);
    printf("The number of iteration n is: %d", n);


    return 0;
}