# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

// Struct Definition
typedef struct {
    int *arr;
    int size;
    int capacity;
} MaxHeap;


// Creating a heap with capacity && Destroying heap
MaxHeap* createHeap(int capacity){
    if (capacity <= 0){
        fprintf(stderr, "Capacity must be greater than 0");
        return NULL;
    }

    MaxHeap* heap = (MaxHeap*) malloc (sizeof(MaxHeap));
    if (!heap){
        fprintf(stderr, "Memory allocation failed, heap not created\n");
        exit(EXIT_FAILURE);
    }

    heap->arr = (int*) malloc(capacity * sizeof(int));
    if (!heap->arr){
        fprintf(stderr, "Memory allocation failed\n");
        free(heap);
        return NULL;
    }

    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}

// Free all allocated memory
void destroyHeap(MaxHeap* heap) {
    if (heap) {
        free(heap->arr);
        free(heap);
    }
}

// Helper functions & Utilities
void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(MaxHeap* heap, int ind){
    // do it iteratively
    while(1){
        int largest = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        if (left < heap->size && heap->arr[left] > heap->arr[largest]){
            largest = left;
        }

        if (right < heap->size && heap->arr[right] > heap->arr[largest]){
            largest = right;
        }

        if (largest == ind) {
            break;
        }

        if (largest != ind){
            swap(&heap->arr[ind], &heap->arr[largest]);
            ind = largest;
        }
    }
}

// Restore heap properties
void heapifyUp (MaxHeap* heap, int ind){
    while (ind > 0){
        int parent = (ind - 1) / 2;

        if (heap->arr[ind] <= heap->arr[parent]){
            break;
        }

        swap(&heap->arr[ind], &heap->arr[parent]);
        ind = parent;
    }
}

// Heap operations

void insert(MaxHeap* heap, int val){
    if (!heap){
        fprintf(stderr, "Heap is NULL\n");
        return;
    }

    if (heap->size >= heap->capacity){
        fprintf(stderr, "Heap is full, can not add anymore\n");
        return;
    }
    
    heap->arr[heap->size] = val;
    heap->size++;

    heapifyUp(heap, heap->size - 1);
}

// Extract Max
int extractMax (MaxHeap* heap){
    if (!heap || heap->size == 0){
        fprintf(stderr, "Error: Cannot extract from empty heap.\n");
        return INT_MIN; 
    }

    int maxVal = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    if (heap->size > 0){
        heapifyDown(heap, 0);
    }

    return maxVal;
}

// Return max without removing it
int peekMax(MaxHeap* heap) {
    if (!heap || heap->size == 0) {
        fprintf(stderr, "Error: Heap is empty.\n");
        return INT_MIN;
    }
    return heap->arr[0];
}

// Check if heap is empty
int isEmpty(MaxHeap* heap) {
    return heap && heap->size == 0;
}

// Get current number of elements
int getSize(MaxHeap* heap) {
    return heap ? heap->size : 0;
}

// Print heap contents (for debugging)
void printHeap(MaxHeap* heap) {
    if (!heap || heap->size == 0) {
        printf("Heap: (empty)\n");
        return;
    }
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("(size=%d, cap=%d)\n", heap->size, heap->capacity);
}

int main() {
    // Create heap with capacity for 10 elements
    MaxHeap* heap = createHeap(10);
    if (!heap) return 1;

    // Insert elements
    printf("Inserting: 10, 20, 15, 30, 40\n");
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 30);
    insert(heap, 40);

    printHeap(heap);
    printf("Max: %d\n\n", peekMax(heap));

    // Extract all elements
    printf("Extracting max elements:\n");
    while (!isEmpty(heap)) {
        int val = extractMax(heap);
        printf("Extracted: %d", val);
        if (!isEmpty(heap)) {
            printf(" -> New max: %d", peekMax(heap));
        }
        printf("\n");
    }

    printHeap(heap);

    // Clean up
    destroyHeap(heap);
    return 0;
}