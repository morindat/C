# include <stdio.h>
# include <stdlib.h>

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort(int *arr, int n){

    /**
     * for each element of the array
     * compare it with the next one
     * swap if the next is smaller
     * repeat
     * also keep count of the number of swaps perfomed
     */

    int swapCount = 0;

    for (int i = 0; i < n; i++){
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swapCount++;
                swapped = 1;
            }
        }

        if (!swapped){
            break;
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
    int swaps = bubbleSort(arr, n);
    printArr(arr, n);

    printf("Number of swaps: %d\n", swaps);

    return 0;
}