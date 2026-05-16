# include <stdio.h>


int hanoi_rec(int n){
    if (n == 1) return 1;
    return 2 * hanoi_rec(n - 1) + 1;
}

int hanoi_closed(int n){
    return (1 << n) - 1;
}

int main(){
    int k;
    printf("Enter number of disks: ");
    scanf("%d", &k);

    printf("Using recurrence: %d\n", hanoi_rec(k));
    printf("Using closed form: %d\n", hanoi_closed(k));

    return 0;
}