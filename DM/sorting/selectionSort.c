# include <stdio.h>
# include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int selectionSort(int *arr, int n){
    /**
     * the idea is, for each iteration, find the min element and swap with the element
     * at the index we are at
     */
    
    int swapCount = 0;

    for (int i = 0; i < n - 1; i++){
        int minIndex = i;

        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        if (minIndex != i){
            swap(&arr[i], &arr[minIndex]);
            swapCount++;
        }
    }

    return swapCount;
}

void printArr(int* arr, int n){
    printf("Array: ");

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(){
    int arr[5] = {3, 2, 1, 5, 4};
    int n = 5;

    printArr(arr, n);
    int swaps = selectionSort(arr, n);
    printArr(arr, n);

    printf("Number of swaps: %d\n", swaps);

    return 0;
}