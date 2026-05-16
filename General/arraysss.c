#include <stdio.h>

int main() {
    int a[5];
    int n = 5, max;

    printf("Please enter numbers separated by blank: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    printf("Maximum of: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("is: %d\n", max);

    return 0;
}