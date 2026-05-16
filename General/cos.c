# define _USE_MATH_DEFINES
# include <stdio.h>
# include <math.h>

double factorial (int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++){
        result *=i;
    }
    return result;
}

int main (){
    double approx = 0.0;
    double x = M_PI / 2;
    double act = cos(x);
    double error;
    double term = 1.0;
    int n = 0;
    double prec = 0.0001;

    while (fabs(term) > prec){
        approx += term;
        n ++;
        double power = 2 * n;
        term = (n % 2 == 0 ? 1 : -1) * pow(x, power) / factorial (power);
    }

    error = fabs(approx - act);

    printf("Actual: %.10f\n", act);
    printf("Approximated: %.10f\n", approx);
    printf("Error: %.10f\n", error);

    return 0;
}