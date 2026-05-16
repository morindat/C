# include <stdio.h>

int fibIteration(int n){
    int a = 0; 
    int b = 1;

    for (int i = 2; i <= n; i++){
        int c = a + b;
        a = b; 
        b = c;
    }

    return b;
}

int fibRecursive(int n){
    if (n <= 1) return n;

    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fibMemo(int n, int *dp){
    if (n <= 1) return n;

    if (dp[n] != -1){
        return dp[n];
    }

    dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
    return dp[n];
}

int fibDP(int n){
    if (n <= 1) return n;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(){
    int n = 10;

    printf("Iterative: %d\n", fibIteration(n));
    printf("Recursive: %d\n", fibRecursive(n));

    int dp[100];
    for (int i = 0; i < 100; i++)
        dp[i] = -1;

    printf("Memoization: %d\n", fibMemo(n, dp));
    printf("DP: %d\n", fibDP(n));
}