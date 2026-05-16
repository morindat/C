# include <stdio.h>
# include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high){
    /**
     * Choose the last element as the pivot
     * choose i at low - 1
     * comparison goes this way
     * if the elemment we are looking at is > pivot, do nothing
     * otherwise increment i and swap
     * continue to the end
     * return i + 1 (position of the pivot)
     */

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // now just swap the element at i + 1 and the pivot
    // return the position of the pivot
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int *arr, int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot  + 1, high);
    }
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
    quickSort(arr, 0, n - 1);
    printArr(arr, n);

    return 0;
}