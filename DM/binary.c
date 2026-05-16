#include <stdio.h>
#include <math.h>

int binaryRec(int n){
    if (n == 1) return 1;
    
    return binaryRec(n/2) + 1;
}

int binaryClosed(int n){
    return (int)(log2(n)) + 1;
}

int main(){
    int k;

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Recursive: %d\n", binaryRec(k));
    printf("Closed form: %d\n", binaryClosed(k));

    return 0;
}