# include <stdio.h>
# include <stdlib.h>

int main(){
    // MALLOC
    // Create a pointer array with an allocated space for 10 integers
    // Points to the start of the heap

    int *arr = malloc (10 * sizeof(int));
    
    // Add check to see if the array was allocated space correctly
    
    if (arr == NULL){
        fprintf(stderr, "Allocation failed miserably!");
        exist(1);
    }

    // CALLOC
    // Initializes the elements of the array to 0

    int *arr = calloc(10, sizeof(int)); 

    // Also done like this

    int *arr = malloc(10 * sizeof(int));
    memset(arr, 0, 10 * sizeof(int));

    
    // REALLOC
    int *arr = malloc(10 * sizeof(int));
    int *temp = realloc(arr, 10 * sizeof(int));
    if (temp == NULL){
        fprintf(stderr, "Reallocation failed miserably!");
        free(arr);
        exit(1);
    }

    arr = temp; // SUCCESS

    // FREE
    free(arr);
    arr = NULL;

    return 0;
}