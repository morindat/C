# include <stdio.h>
# include <stdlib.h>

int main(){
    int n;
    printf("Please enter the size of an array: ");
    scanf("%d", &n);

    // Step 1: Allocate

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL){
        fprintf(stderr, "Allocation failed miserably!\n");
        return 1;
    }

    // Step 2: Use

    for (int i = 0; i < n; i++){
        arr[i] = i * 10;
    }

    // Step 3: Print

    for (int i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Step 4: Free

    free(arr);
    arr = NULL;

    return 0;
}