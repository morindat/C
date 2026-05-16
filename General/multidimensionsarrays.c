# include <stdio.h>

void printarr(int row, int col, int A[row][col]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int row, col;

    printf("Please enter the number of rows for the arrays: ");
    scanf("%d", &row);

    printf("Please enter the number of columns for the arrays: ");
    scanf("%d", &col);

    int A[row][col], B[row][col], sum[row][col], mult[row][col];

    printf("Please enter the element of the array A row by row separated by space: \n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Please enter the element of the array B row by row separated by space: \n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            scanf("%d", &B[i][j]);
        }
    }

    // Addition
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
    
    // Multiplication
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            mult[i][j] = 0;
            for (int k = 0; k < row; k++){
                mult[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("The sum array is: \n");
    printarr(row, col, sum);
    printf("The product array is: \n");
    printarr(row, col, mult);

}