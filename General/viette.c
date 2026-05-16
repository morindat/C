# include <stdio.h>
# include <math.h>

double viette(double c, double prev, double product, int *k, double actual){
    (*k)++;
    double next = sqrt(2.0 + prev);
    product *= (next / 2.0);
    double approx = 2.0 / product;

    if (fabs(actual - approx) <= c){
        return approx;
    }
    else{
        return viette(c, next, product, k, actual);
    }
}

int sum_digits(int n){
    int sum = 0;
    if (n < 10) return n;
    else{
        while (n != 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
}

int sum_rec(int n){
    if (n < 10) return n;
    else{
        return n % 10 + sum_rec(n/10);
    }
}

int countDigits(int num) {
    if (num < 10) {
        return 1;
    }
    return 1 + countDigits(num / 10); 
}

int num_reverse(int num) {
    if (num < 10) {
        return num;
    }

    // Recursive step:
    int lastDigit = num % 10;          
    int remaining = num / 10;     
    int numDigits = countDigits(remaining); 

   
    return lastDigit * (int)power(10, numDigits) + num_reverse(remaining);
}

int power(int base, int exp) {
    if (exp == 0) {
        return 1; 
    }
    return base * power(base, exp - 1); 
}

int main(){
    int k = 0;
    int n = 12345;
    double c;
    
    printf("Please enter the tolerance level: ");
    scanf("%lf", &c);

    double actual = M_PI;
    double a0 = sqrt(2.0);
    double initial_product = a0 / 2.0;

    double approx = viette(c, a0, initial_product, &k, actual);
    int res = sum_digits(n);
    int result = sum_rec(n);
    int rev = num_reverse(n);


    printf("The real value of pi is: %lf\n", actual);
    printf("The approximated value of pi is: %lf\n", approx);
    printf("The number of steps it took is: %d\n", k);
    printf("The sum of digits in %d is: %d\n", n, res);
    printf("The sum of digits rec in %d is: %d\n", n, result);
    printf("The reverse of %d is: %d", n, rev);

    return 0;
}