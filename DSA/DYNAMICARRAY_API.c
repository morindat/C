# include <stdio.h>
# include <stdlib.h>

typedef struct{
    int *data;
    size_t capacity;
    size_t size;
} DynamicArr;

DynamicArr * initDynamicArr(size_t initCapacity){
    DynamicArr *arr = malloc (sizeof(*arr));

    if (arr == NULL){
        free(arr);
        return NULL;
    };

    arr->data = NULL;
    arr->capacity = initCapacity;
    arr->size = 0;

    if (initCapacity > 0){
        arr->data = malloc (initCapacity * sizeof(*arr->data));
        if (arr->data == NULL){
            free(arr);
            return NULL;
        }
    }

    return arr;

}

void freeDynamicArr (DynamicArr *arr){
    if (arr){
        free(arr->data);
        free(arr);
    }
}

int ensureCapacity (DynamicArr *arr){
    if (arr->size >= arr->capacity){
        size_t newCapacity = (arr->capacity == 0) ? 1 : 2 * arr->capacity;
        int *newdata =  realloc (arr->data, newCapacity * sizeof(int));
        if (newdata == NULL) return 0; 

        arr->data = newdata;
        arr->capacity = newCapacity;
    }

    return 1;
}


int resize (DynamicArr *arr){
    if (arr == NULL) return 0;

    if (arr->capacity > arr->size + 2){
        size_t newCapacity = arr->size + 2;

        int *newdata = realloc (arr->data, newCapacity * sizeof(int));
        if (newdata == NULL) return 0;

        arr->data = newdata;
        arr->capacity = newCapacity;
    }
    return 1;
}

int append(DynamicArr *arr, int value) {
    if (!ensureCapacity(arr)) return 0; 
    
    arr->data[arr->size++] = value;     
    return 1;                           
}

int getElement(DynamicArr *arr, size_t index, int *out){
    if (arr == NULL || out == NULL) return 0;

    if (index >= arr->size){
        printf("Index out of bounds, please check again!");
        return 0;
    }

    *out = arr->data[index];
    return 1;
} 

int findElement (DynamicArr *arr, int val){
    if (arr == NULL) return 0;

    for (size_t i = 0; i < arr->size; i++){
        if (arr->data[i] == val){
            return i;
        }
    }
    return -1;
}

int setElement(DynamicArr *arr, size_t index, int val){
    if (arr == NULL) return 0;

    if (index < arr->size){
        arr->data[index] = val;
        return 1;
    }

    return 0;
}

int insertAt(DynamicArr *arr, size_t index, int val){
    if (arr == NULL) return 0;
    if (!ensureCapacity(arr)) return 0;

    if (index > arr->size){
        printf("Index out of bound!");
        return 0;
    }

    for (size_t i = arr->size; i > index; i--){
        arr->data[i] = arr->data[i - 1];
    }

    arr->data[index] = val;
    arr->size++;
    
    return 1;
}

int removeAt(DynamicArr *arr, size_t index){
    if (arr == NULL || index >= arr->size){
        fprintf(stderr, "Invalid index!");
        return 0;
    }

    for (size_t i = index; i < arr->size - 1; i++){
        arr->data[i] = arr->data[i+1];
    }

    arr->size--;

    return 1;
}

int pop (DynamicArr *arr, int *out){
    if (arr == NULL || arr->size == 0){
        fprintf(stderr, "Cannot pop!");
        return 0;
    }

    if (out != NULL){
        *out = arr->data[arr->size-1];
    }
    
    arr->size--;
    return 1;
}

int getSize(DynamicArr *arr){
    if (arr == NULL) return -1;
    
    return arr->size;
}

int getCapacity(DynamicArr *arr){
    if (arr == NULL) return -1;

    return arr->capacity;
}

int isEmpty(DynamicArr *arr){
    if (arr == NULL) return 0;

    if (arr->size == 0) return 1;
    return 0;

    // return (arr != NULL && arr->size == 0);
}

void print(DynamicArr *arr){

    if (arr == NULL) {
        printf("Array is NULL.\n");
        return;
    }

    int size = getSize(arr);
    int capacity = getCapacity(arr);

    if (size == -1 || capacity == -1) {
        printf("Failed to get array size or capacity.\n");
        return;
    }

    printf ("Array -> (size: %d and capacity: %d): \n", size, capacity);
    printf("[ ");
    for (size_t i = 0; i < arr->size; i++){
        printf("%zu ", arr->data[i]);
    }
    printf("]\n");
}


int main(){
    printf("Everything is working!\n");
    DynamicArr * arr = initDynamicArr(5);
    if (arr == NULL){
        fprintf(stderr, "Memo allocation failed");
        exit(1);
    }

    append(arr, 10);
    append(arr, 20);
    append(arr, 30);
    append(arr, 40);
    append(arr, 50);
    append(arr, 60);
    append(arr, 70);
    append(arr, 80);
    append(arr, 90);
    append(arr, 100);
    print(arr);
    int val;
    pop(arr, &val);
    print(arr);
    insertAt(arr, 2, 110);
    print (arr);
    removeAt(arr, 2);
    print(arr);
    setElement(arr, 2, 200);
    print(arr);
    if (findElement(arr, 200)){
        printf("Found\n");
    }
    else{
        printf("Not found!\n");
    }


    printf("Size: %d\n", getSize(arr));
    printf("Capacity: %d\n", getCapacity(arr));
    printf("Is Empty: %d\n", isEmpty(arr));

    freeDynamicArr(arr);

    return 0;
}