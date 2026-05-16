# include <stdio.h>

int sumrec(int n){
    if(n == 0 || n == 1){
        return n;
    }
    else{
        return n + sumrec(n - 1);
    }
}

int sumclosed(int n){
    return n*(n + 1) / 2;
}

int sumoddrec(int n){
    if (n == 0 || n == 1){
        return n;
    }
    else {
        return (2*n - 1) + sumoddrec(n - 1);
    }
}

int sumoddclosed(int n){
    return n*n;
}

int sumsqrrec(int n){
    if (n == 0 || n == 1){
        return n;
    }
    else {
        return n*n + sumsqrrec(n-1);
    }
}

int sumsqrclosed(int n){
    return n*(n + 1)*(2*n + 1) / 6;
}

int fibrec(int n){
    if(n == 0 || n == 1){
        return n;
    }
     else {
        return fibrec(n-2) + fibrec(n-1);
     }  
}

int fibiter(int n){
    if (n == 0 || n == 1){
        return n;
    }
    else{
        int prev = 0;
        int curr = 1;

        for (int i = 2; i <= n; i ++){
            int next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }
    
}

int factrec(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * factrec(n - 1);
    }
}

int factiter(int n){
    int factoo = 1;
    for (int i = 1; i <= n; i++){
        factoo *= i;
    }
    return factoo;
}

int main(){

    int n = 100;
    int x = 12;
    int result = sumrec(n);
    int sum = sumclosed(n);
    int odd = sumoddrec(n);
    int odde = sumoddclosed(n);
    int sumsqr = sumsqrrec(n);
    int sumclosed = sumsqrclosed(n);
    int fib = fibrec(x);
    int fib2 = fibiter(x);
    int facto = factrec(x);
    int factoo = factiter(x);

    printf("Sum rec: %d\n", result);
    printf("Sum closed: %d\n", sum);
    printf("Sum odd rec: %d\n", odd);
    printf("Sum odd closed: %d\n", odde);
    printf("Sum sqr rec: %d\n", sumsqr);
    printf("Sum sqr closed: %d\n", sumclosed);
    printf("Fibonacci rec: %d\n", fib);
    printf("Fibonacci iter: %d\n", fib2);
    printf("Factorial rec: %d\n", facto);
    printf("Factorial iter: %d\n", factoo);


    return 0;
}