# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <time.h>

#define MAX_N 1000

bool isPrime(int n){
    if (n < 2) return false;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }

    return true;
}

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


bool isPrimeFermat(long long n, long long k){
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    
    for (int i = 1; i <= k; i++){
        long long a = 2 + rand() % (n -3);
        if ((binpow(a, n-1, n)) != 1){
            printf("Fails when a = %lli.\n", a);
            return false;
        }
    }

    return true;
}

int generate_primes(int n, int primes[]) {
    int count = 0;

    for (int i = 2; i <= n; i++) {
        bool is_prime = true;

        for (int j = 0; j < count; j++) {
            int p = primes[j];
            if (p * p > i) break;
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            primes[count++] = i;
        }
    }

    return count;
}

int smallestWithKPrimeFactors(int k) {
    int count = 0, n = 25;
    long long result = 1;

    while (count < k) {
        if (isPrime(n)) {
            result *= n;
            count++;
        }
        n++;
    }

    return result;
}


int main(){
    srand(time(0));

    long long n = 31697;
    printf("Fermat test: %s\n", (isPrimeFermat(n, 100)) ? "Probably Prime" : "Composite");

    int primes[MAX_N];
    int limit = 1000;

    int count = generate_primes(limit, primes);

    printf("Primes up to %d:\n", limit);
    for (int i = 0; i < count; ++i) {
        printf("%d ", primes[i]);
    }
    printf("\nTotal primes found: %d\n", count);

    return 0;
}