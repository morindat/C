# include <stdio.h>
# include <stdlib.h>


int *arr = NULL;
int count = 0;
int capacity = 0;

void append(int value){
    if (count >= capacity){
        capacity = (capacity == 0) ? 1 : capacity * 2;
        arr = realloc(arr, capacity * sizeof(int));
        if(arr == NULL){
            fprintf(stderr, "Reallocation failed!\n");
            exit(1);
        }
    }
    arr[count++] = value;
}


int main(){
    append(10);
    append(20);
    append(30);
    append(40);

    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    // Output: 10 20 30 40

    free(arr);

    return 0;
}