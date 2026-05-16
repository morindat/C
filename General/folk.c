# include <stdio.h>

int main (){
    int k, n;
    printf("Please enter k: ");
    scanf("%d", &k);
    printf("Please enter n: ");
    scanf("%d", &n);

    int quo = k / n;
    int rem2 = k - (quo * n);
    printf("Remainder: %d", rem2);
    

    return 0;
}