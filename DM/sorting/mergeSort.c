# include <stdio.h>
# include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int *arr, int left, int mid, int right){
    int n = mid - left + 1;
    int m = right - mid;

    int L[n];
    int R[m];

    for (int i = 0; i < n; i++){
        L[i] = arr[left + i];
    }

    for (int i = 0; i < m; i++){
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n && j < m){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n){
        arr[k] = L[i];
        i++; k++;
    }

    while (j < m){
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int *arr, int left, int right){
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n - 1);
    printArr(arr, n);

    return 0;
}