# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define MAX 100

// min and max problem

void MinMax(int arr[], int n, int *min, int *max){
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < n; i++){
        if (arr[i] > *max){
            *max = arr[i];
        }
        if (arr[i] < *min){
            *min = arr[i];
        }
    }
}

// Sec greater problem

int secGreater(int arr[], int n){

    int first = INT_MIN;
    int sec = INT_MIN;

    for (int i = 0; i < n; i++){
        if (arr[i] > first){
            sec = first;
            first = arr[i];
        } else if (arr[i] > sec && arr[i] != first){
            sec = arr[i];
        }
    }

    return (sec == INT_MIN ? -1 : sec);
}

// Find Median Problem

int cmp (const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

double find_med(int arr[], int n){
    qsort(arr, n, sizeof(int), cmp);

    if (n % 2 == 0){
        return arr[n/2];
    } else {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    }
}

int main(){

    int arr[] = {4, 3, 6, 9, -9};
    int n = 5;
    
    int min;
    int max;

    MinMax(arr, n, &min, &max);

    double median = find_med(arr, n);
    if (median == (int)median){
        printf("Median: %d\n", (int)median);
    } else {
        printf("Median: %.2lf\n", median);
    }

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    int v = secGreater(arr, n);
    printf("Sec max: %d\n", v);


    for (int i = 1; i <= n; i++){
        printf("%d ", i);
    }

    return 0;
}