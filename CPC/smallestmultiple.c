# include <stdio.h>
# include <stdbool.h>
# include <math.h>


void sieve(int n, bool primes[]){
    // Initialize the primes array with 1s

    for (int i = 2; i <= n; i++){
        primes[i] = true;
    }

    // Remove multiples

    for (int i = 2; i * i <= n; i++){
        if (primes[i]){
            for (int j = i * i; j <= n; j += i){
                primes[j] = false;
            }
        }
    }
}

void print(int n, bool primes[]){
    for (int i = 2; i <= n; i++){
        if (primes[i]){
            printf("%d ", i);
        }
    }
    printf("\n");
}

unsigned long long smallest (int n){
    bool primes[n + 1];
    sieve(n, primes);
    
    unsigned long long lcm = 1;

    for (int i = 2; i <= n; i ++){
        if (primes[i]){
            int power = (int) (log(n) / log(i));
            unsigned long long p_power = 1;

            for (int j = 0; j < power; j++){
                p_power *= i;
            }
            lcm *= p_power;
        }
    }
    return lcm;
}

int main(){
    int n = 20;
    bool primes[n+1];
    sieve(n, primes);
    print(n, primes);

    unsigned long long result = smallest(n);
    printf("Smallest number divisible by all numbers from 1 to %d is: %llu\n", n, result);
    return 0;

    return 0;
}