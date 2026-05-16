# include <stdio.h>
# include <math.h>

double baby(double r, double c, double prev, int *k){
    (*k) ++;
    double next = 0.5 * (prev + (r / prev));

    if (fabs(sqrt(r) - next) <= c){
        return next;
    }
    else{
        return baby(r, c, next, k);
    }
}

double newton(double r, double c, double prev_term, int *x){
    (*x) ++;
    double next_term = (1.0 / 3) *(2*prev_term + (r / (prev_term * prev_term)));

    if (fabs(cbrt(r) - next_term) <= c){
        return next_term;
    }
    else{
        return newton(r, c, next_term, x);
    }
}

long long int hanoi(int n){
    if (n == 1) return 1;
    else{
        return 2 * hanoi(n - 1) + 1;
    }
}

long long int thanoi(int n){
    return pow(2, n) - 1;
}

int main(){
    double r, c;
    int k = 0;
    int x = 0;

    printf("Please enter the valuer r: ");
    scanf("%lf", &r);
    if (r <= 0){
        printf("Error: r must be greater than 0.\n");
        return 1;
    }

    printf("Please enter the value c in range (0, 1): ");
    scanf("%lf", &c);
    if(c <= 0 || c >= 1){
        printf("Error: c must be in the given range.\n");
        return 1;
    }

    double prev = r / 2;
    double cube_approx = newton(r, c, prev, &x);
    double approx = baby(r, c, prev, &k);
    double real = sqrt(r);
    double cube_real = cbrt(r);
    long long int moves = hanoi(r);
    long long int movess = thanoi(r);

    printf("Approximated square root of %.6lf: %.6lf\n", r, approx);
    printf("The real value of square root of %.6lf: %.6lf\n", r, real);
    printf("Smallest integer k for which (|sqrt(%.6lf) - ak| <= %.6lf): %d\n", r, c, k);
    printf("\n");
    printf("Approximated cube root of %.6lf: %.6lf\n", r, cube_approx);
    printf("The real value of square root of %.6lf: %.6lf\n", r, cube_real);
    printf("Smallest integer k for which (|cbrt(%.6lf) - ak| <= %.6lf): %d\n", r, c, x);
    printf("\n");
    printf("The number of moves (recursively) needed are: %d\n", moves);
    printf("The number of moves (Iteratively) needed are: %d", movess);

    return 0;
}