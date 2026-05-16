#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    int leftarr[n1], rightarr[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
        leftarr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightarr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left; // Initial indices for subarrays

    // Merge the temporary arrays back into arr[]
    while (i < n1 && j < n2) {
        if (leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        } else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftarr[], if any
    while (i < n1) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightarr[], if any
    while (j < n2) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Correct mid calculation

        // Recursively sort first and second halves
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void print_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 21, 3, 5, 7, 8, 0, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("The original array: \n");
    print_arr(arr, size);

    mergesort(arr, 0, size - 1);

    printf("The sorted array: \n");
    print_arr(arr, size);

    return 0;
}