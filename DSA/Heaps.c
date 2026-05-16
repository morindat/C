# include <stdlib.h>
# include<stdio.h>

typedef struct Heap {
    int* arr;
    int capacity;
    int size;
} Heap;

Heap* createHeap(int capacity){
    // alocate memory for each heap/node and arr
    Heap* newHeap = (Heap*)malloc (sizeof(Heap));
    int* arr = (int*) malloc(capacity * sizeof(int));

    // Initialize the fields of the heap
    newHeap->size = 0;
    newHeap->capacity = capacity;

    return newHeap;
}

void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion in max heap
// we do not want any element added to be larger than the parent node
// if that happens we need to swap untill the parent heap is the max
// and we will achieve this by a heapifyUp fun
// here it goes

void heapifyUp (Heap* heap, int i){
    int parent = (i - 1) / 2; // array representation of a heap
    // now we need to check if the element is greater than the parent heap and swap until that is not the case
    // recursively btw
    if (i > 0 && heap->arr[i] > heap->arr[parent]){
        swap(&heap->arr[i], &heap->arr[parent]);
        heapifyUp(heap, parent); // repeate until it is not the case that node is greater than parent heap
    }
}

// Add the element to the end of the heap
// heapifyUp to find its correct position
// increase size

void insert (Heap* heap, int val){
    if (heap->size == heap->capacity){
        fprintf(stderr, "Heap full");
        exit(EXIT_FAILURE);
    }

    heap->arr[heap->size] = val;
    heapifyUp(heap, heap->size);
    heap->size++;
}

void printHeap(Heap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// Extract max

void heapifyDown (Heap* heap, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[i]){
        largest = left;
    }

    if (right < heap->size && heap->arr[right] > heap->arr[i]){
        largest = right;
    }

    if (largest != i){
        swap(&heap->arr[i], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }

}

int extractMax (Heap* heap){
    if (heap->size == 0) return -1;
    if (heap->size == 1) return heap->arr[--heap->size];

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);

    return root;
}

// Peek
int peek (Heap* heap){
    if (heap->size <= 0){
        fprintf(stderr, "Heap is empty!\n");
        exit(EXIT_FAILURE);
    }

    return heap->arr[0];
}

// heapify

Heap* heapify(int* arr, int n){
    Heap* heap = createHeap(n);
    heap->arr = arr;
    heap->capacity =n;
    heap->size = n;

    for (int i = (n/2); i >= 0; i--){
        heapifyDown(heap, i);
    }

    return heap;
}

int main() {
    Heap* heap = createHeap(10);

    insert(heap, 40);
    insert(heap, 30);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 10);

    printf("Heap after first inserts: ");
    printHeap(heap);  

    insert(heap, 50); 
    printf("Heap after inserting 50: ");
    printHeap(heap);  

    int max = extractMax(heap);
    int chabo = peek(heap);
    printf("Extracted Max: %d\n", max);
    printf("Element at the top is: %d\n", chabo);

    printf("Heap after extraction: ");
    printHeap(heap);

    return 0;
}