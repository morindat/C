# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <time.h>

// Trial Division method
bool isPrime(int n){
    if (n < 2) return false;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }

    return true;
}

bool isPrimeOptimized(int n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i+=2){
        if (n % i == 0) return false;
    }

    return true;
}

// Fermat's Method
long long binpow(long long base, long long exp, long long mod){
    long long res = 1;
    base %= mod;

    while(exp > 0){
        if (exp % 2 == 1){
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return res;

}

bool isPrimeFermat(long long n, long long a){
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    
    for (int i = 1; i <= a; i++){
        long long x = 2 + rand() % (n -3);
        if ((binpow(x, n-1, n)) != 1){
            return false;
        }
    }

    return true;
}


// Miller Rabin test
bool checkComposite(long long n, long long a, long long d, int r){
    long long x = binpow(a, d, n);
    
    if (x == 1 || x == n - 1)
        return false;

    for (int i = 1; i < r; i++){
        x = (x * x) % n;
        if(x == n - 1)
            return false;
    }

    return true;
}

bool isPrimeMiller(long long n, int iterations){
    if (n < 2) return false;
    if (n == 2|| n == 3) return true;
    if (n % 2 == 0) return false;

    // express n - 1 as 2^r * d

    int r = 0;
    long long d = n - 1;

    while(d % 2 == 0){
        d /= 2;
        r++;
    }

    for (int i = 0; i < iterations; i++){
        long long a = 2 + rand() % (n - 3);
        if (checkComposite(n, a, d, r))
            return false;
    }

    return true;

}

bool isPrimeDeterministic(long long n, int iterations){
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    int r = 0;
    long long d = n - 1;

    while(d % 2 == 0){
        d /= 2;
        r++;
    }

    int bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int baseCount = sizeof(bases) /sizeof(bases[0]);

    for (int i = 0; i < baseCount; i++){
        if (bases[i] >= n) break;
        if (checkComposite(n, bases[i], d, r))
            return false;
    }

    return true;

}

void sieve(int a, int b) {
    bool isPrime[b + 1];

    for (int i = 0; i <= b; i++)
        isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= b; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= b; i += p) {
                isPrime[i] = false;
            }
        }
    }

    printf("Primes between %d and %d:\n", a, b);
    for (int i = a; i <= b; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}


int main() {
    srand(time(NULL));  // Seed for random numbers

    long long n = 994449669898999;
    printf("Testing %lld\n", n);
    printf("Trial: %s\n", isPrime(n) ? "Prime" : "Composite");
    printf("Optimized Trial: %s\n", isPrimeOptimized(n) ? "Prime" : "Composite");
    printf("Fermat: %s\n", isPrimeFermat(n, 5) ? "Probably Prime" : "Composite");
    printf("Miller-Rabin: %s\n", isPrimeMiller(n, 5) ? "Probably Prime" : "Composite");
    printf("Deterministic Miller-Rabin: %s\n", isPrimeDeterministic(n, 0) ? "Prime" : "Composite");
}
