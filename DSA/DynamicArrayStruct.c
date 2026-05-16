# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

// Initialization
// Create a function initDynamicArray that returns a pointer to the struct Dynamic Array with an initialCapacity argument
// Create the dynamic array with type definition dynamic aray
// The data is the array itself, so remember to initialize it too with int as type def
// Initialize the size to zero and capacity to initial capacity

DynamicArray *initDynamicArr(size_t initCapacity){

    // Step 1: Allocate the container and check for malloc failure

    DynamicArray *arr = malloc (sizeof(*arr));
    if (arr == NULL){
        free(arr);
        return NULL;
    }

    // Step 2: Initialize struct properties

    arr->data = NULL;
    arr->size = 0;
    arr->capacity = initCapacity;

    // Step 3: Handle initial capacity being 0 and initialization of data buffer

    if (initCapacity > 0){
        arr->data = malloc(initCapacity * sizeof(*arr->data));
        if(arr->data == NULL){
            free(arr);
            return NULL;
        }
    }
    
    return arr;
}

// Appending elements

int append (DynamicArray *arr, int value){

    // Check if the container array is malloc-ed successfully

    if (arr == NULL) return 0;

    // Check the size and capacity of the arr
    // If the size is greater than capacity. Check whether the capacity is 0, if yes, then add one and else double it
    // Create a new container to hold the data appended

    if (arr->size >= arr->capacity){
        size_t newCapacity = arr->capacity == 0 ? 1 : arr->capacity * 2;
        int *newdata = (int *) realloc (arr->data, newCapacity * sizeof(int));
        if (newdata == NULL) return 0;

        arr->data = newdata;
        arr->capacity = newCapacity;
    }

    arr->data[arr->size] = value;
    arr->size++;
    return 1;
}

// Getters and Setters

int getValue (DynamicArray *arr, size_t index, int *value){
    if (arr == NULL || index >= arr->size) return 0;
    *value = arr->data[index];
    return 1;
}

int setElement(DynamicArray *arr, size_t index, int value) {
    if (arr == NULL || index >= arr->size) return 0;
    arr->data[index] = value;
    return 1;
}

int resizeArr(DynamicArray *arr, int newCapacity){
    if (arr == NULL) return 0;
    if (newCapacity < arr->size) return 0;

    int *newdata = (int *) realloc (arr->data, newCapacity * sizeof(int));
    if (newdata == NULL) return 0;

    arr->data = newdata;
    arr->capacity = newCapacity;
    return 1;

}

// FREE

void Free(DynamicArray *arr){
    if (arr){
        free(arr->data);
        free(arr);
    }
}

void findMinMax(DynamicArray *arr, int *min, int *max){
    if (arr == NULL || arr->size == 0) return;

    *min = *max = arr->data[0];
    for(size_t i = 0; i < arr->size; i++){
        if (arr->data[i] < *min) *min = arr->data[i];
        if (arr->data[i] > *max) *max = arr->data[i];
    }
}

int main(){
    // Initialize the dynamic array

    DynamicArray *arr = initDynamicArr(10);
    if (arr == NULL) {
        printf("Failed to initialize array\n");
        return 1;
    }
    else{
        printf("Inialized successfully!\n");
    }

    // Appending values
    int values[] = {1, 2, 3, 4, 5, 6, 7};
    for (size_t i = 0; i < 7; i++){
        if (!append(arr, values[i])){
            printf("Failed to append %d\n", values[i]);
            Free(arr);
            return 1;
        }
    }

    // Print array
    printf("Dynamic Array (size: %zu, capacity: %zu): ", arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++) {
        int value;
        if (getValue(arr, i, &value)) {
            printf("%d ", value);
        }
    }
    printf("\n");

    // Find min and max
    int min, max;
    findMinMax(arr, &min, &max);
    printf("Minimum: %d\nMaximum: %d\n", min, max);

    // Free array
    Free(arr);

    return 0;
}