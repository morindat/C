# include <stdio.h>
# include <stdlib.h>

int main(){
    int arr[5];

    // Taking inputs 1D

    printf("Please enter 5 elements of the Array: \n");
    for(int i = 0; i < 5; i++){
        printf("Value %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");

    // Outputting the array 1D
    // Simply traverse throught the array and output the value

    printf("[ ");
    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("]");

    printf("\n");

    // Taking inputs 2D
    /*
    1. Declare the rows and cols of the array with values
    2. Decleare the array and include the cols and rows
    3. Values are taken row by row
    */

   int row = 2;
   int col = 2;

   int array[2][2];

   printf("Enter the elements of 2D array: \n");
   for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &array[i][j]);
        }
   }
   printf("\n");

    // Outputting 2D
    // Done in similar manner

    printf("2D array: \n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}