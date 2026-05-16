# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <time.h>

long long binpow(long long base, long long expo, long long mod){
    long long res = 1;
    base %= mod;

    while(expo > 0){
        if (expo %2 == 1){
            res = (res * base) % mod;
        } 
        base = (base * base) % mod;
        expo /= 2;
    }

    return res;
}

bool isPrime(int n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i*i <= n; i+=2){
        if (n % i == 0) return false;
    }

    return true;
}

bool isPrimeFermat(long long n, long long k){
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;

    for (int i = 1; i <= k; i++){
        long long x = 2 + rand() % (n -3);

        if (binpow(x, n-1, n) != 1){
            return false;
        }
    }
    
    return true;
}

void sieve(int a, int b){
    bool is_Prime[b + 1];

    for (int i = 0; i <= b; i++){
        is_Prime[i] = true;
    }

    is_Prime[0] = is_Prime[1] = false;

    for (int p = 2; p * p <= b; p++){
        if (is_Prime[p]){
            for (int i = p * p; i <= b; i += p){
                is_Prime[i] = false;
            }
        }
    }

    printf("Primes between %d and %d:\n", a, b);
    for (int i = a; i <= b; i++) {
        if (is_Prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");


}

int main(){
    int a = 2;
    int b = 1000;

    srand(time(0));

    printf("The prime numbers between %d and %d are: \n", a, b);

    for(int i= a; i <= b; i++){
        if (isPrimeFermat(i, 1000) && isPrime(i)){
            printf("%d ", i);
        }
    }
    printf("\n");

    sieve(a, b);

    return 0;
}