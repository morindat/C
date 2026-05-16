# include <stdio.h>
# include <stdlib.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Push the added element all the way up to satisfy the heap condition
// Either the min or max element be at the ind 0
// For any given ind of the lastly added element, find its parent
// If the element is greater or lower than the parent (according to heap condition; min or max) break or swap 
// Update the ind to be parent

void siftUpMaxHeap(int arr[], int ind){
    while (ind > 0){
        int par = (ind - 1) / 2;
        if (arr[ind] <= arr[par]) break;

        swap(&arr[ind], &arr[par]);
        ind = par;
    }
}

void siftUpMinHeap(int arr[], int ind){
    while (ind > 0){
        int par = (ind - 1) / 2;
        if (arr[ind] >= arr[par]) break;

        swap(&arr[ind], &arr[par]);
        ind = par;
    }
}

// the idea here is also simple
// we need to push an element down to its correct location
// assume the index of that element is the largest(normal this is 0 because we use this when we have done deletion)
// Its left and right children can be found 
// Compare the children of the element, get the smaller or larger depending on heap condition, update largest to that ind
// If largest changes, swap the ind and largest elements
// Call the function recursively

void siftDownMaxHeap(int arr[], int ind, int size){
    int largest = ind;
    int left = ( 2 * ind ) + 1;
    int right = ( 2 * ind ) + 2;

    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != ind){
        swap(&arr[ind], &arr[largest]);
        siftDownMaxHeap(arr, largest, size);
    }
}

void siftDownMinHeap(int arr[], int ind, int size){
    int largest = ind;
    int left = ( 2 * ind ) + 1;
    int right = ( 2 * ind ) + 2;

    if (left < size && arr[left] < arr[largest]){
        largest = left;
    }

    if (right < size && arr[right] < arr[largest]){
        largest = right;
    }

    if (largest != ind){
        swap(&arr[ind], &arr[largest]);
        siftDownMinHeap(arr, largest, size);
    }
}

void heapify(int arr[], int size){
    int lastNonLeaf = size / 2 - 1;

    for (int i = lastNonLeaf; i >= 0; i--) {
        siftDownMinHeap(arr, size, i);
    }
}

void print(int arr[], int n){
    for (int i =0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[10];
    int n = 10;

    for (int i = 0; i < n; i++){
        arr[i] = i*i;
    }

    print(arr, n);
    siftDownMaxHeap(arr, 0, n);
    print(arr, n);
    heapify(arr, n);
    print(arr, n);
    siftUpMaxHeap(arr, 9);
    print(arr, n);
    heapify(arr, n);
    print(arr, n);


    return 0;
}