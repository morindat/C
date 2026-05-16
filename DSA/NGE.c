# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define MAX 1000

void nextGreater(int arr[], int n, int res[]){
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) res[i] = -1;

    for (int i = 0; i < n; i++){
        while (top != -1 && arr[i] > arr[stack[top]]){
            res[stack[top]] = arr[i];
            top--;
        }
        stack[++top] = i;
    }

}

void secondGreater(int arr[], int n, int res[]){
    int next[MAX];
    nextGreater(arr, n, next);
    for (int i = 0; i < n; i++) {
        res[i] = -1;
        int ngIdx = -1;
        // Find index of next greater
        for (int j = i+1; j < n; j++) {
            if (arr[j] == next[i]) {
                ngIdx = j;
                break;
            }
        }
        if (ngIdx != -1) {
            for (int k = ngIdx+1; k < n; k++) {
                if (arr[k] > arr[i] && arr[k] > arr[ngIdx]) {
                    res[i] = arr[k];
                    break;
                }
            }
        }
    }
}

int main() {
    int arr[] = {2, 5, 7, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int nextG[MAX], secondG[MAX];
    nextGreater(arr, n, nextG);
    secondGreater(arr, n, secondG);
    printf("Next Greater: ");
    for (int i = 0; i < n; i++) printf("%d ", nextG[i]);
    printf("\nSecond Greater: ");
    for (int i = 0; i < n; i++) printf("%d ", secondG[i]);
    printf("\n");
    return 0;
}