#include <stdio.h>

int sumRecursive(int k)
{
    if (k == 0)
        return 0;
    else
        return sumRecursive(k - 1) + (2 * k - 1);
}

int sumClosed(int k)
{
    return k * k;
}

int main()
{

    int n;
    int sum_recusive, sum_closed;

    printf("Enter the natural num n, upto which the sum needs to be calculated: ");
    scanf("%d", &n);

    sum_recusive = sumRecursive(n);
    sum_closed = sumClosed(n);

    printf("The sum of first %d odd natural numbers, computed recursively is : %d\n", n, sum_recusive);
    printf("The sum of first %d odd natural numbers, computed using closed form is : %d\n", n, sum_closed);

    return 0;
}
