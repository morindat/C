# include <stdio.h>
# include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftUp(int arr[], int ind){
    while (ind > 0){
        int parent = (ind - 1) / 2;
        if (arr[ind] <= arr[parent]){
            break;
        }

        swap(&arr[ind], &arr[parent]);
        ind = parent;
    }
}

void siftUpRec(int arr[], int ind){
    if (ind == 0) return;

    int parent = (ind - 1) / 2;

    if (arr[ind] > arr[parent]){
        swap(&arr[ind], &arr[parent]);
        siftUpRec(arr, parent);
    }

}


void heapifyDown(int arr[], int size, int ind){
    int largest = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != ind){
        swap(&arr[ind], &arr[largest]);
        heapifyDown(arr, size, largest);
    }
}

void buildMaxHeap(int arr[], int size) {
    // Start from last non-leaf node and go up to root
    int lastNonLeaf = size / 2 - 1;
    
    for (int i = lastNonLeaf; i >= 0; i--) {
        heapifyDown(arr, size, i);
    }
}

int main(){
    int arr[] = { 30, 40, 50, 20, 25, 45, 70}; 
    int size = 7;

    buildMaxHeap(arr, 7);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}