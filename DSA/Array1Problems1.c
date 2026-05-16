# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>


void MinMax(int arr[], int size, int *min, int *max){
    if (size <= 0) return;

    *min = *max = arr[0];
    for(int i = 0; i < size; i++){
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }

}

void reverse(int arr[], int size){
    if (size <= 0) return;

    for (int i = size - 1; i > 0; i--){
        printf("%d ", arr[i]);
    }
}

void count(int arr[], int size, int num){
    int freq = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == num){
            freq++;
        }
    }
    printf("The element %d occured %d times in the array.", num, freq);
}

bool is_palindrome(int arr[], int size){
    int left = 0;
    int right = size - 1;

    while (left < right){
        if (arr[left] != arr[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void compute_transpose(int arr[][3], int rows, int cols, int result[][rows]) {
    // Compute transpose: result[i][j] = arr[j][i]
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = arr[j][i];
        }
    }

    // Print the transposed matrix (size: cols × rows)
    printf("Transposed matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int sum(int arr[][3], int rows, int cols){
    int tot = 0;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            tot += arr[i][j];
        }
    }
    return tot;
}



int main(){
    int arr[] = {12, 34, 2, 1, 0, -1, 23, 10, 11, -5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int min, max;
    int num = 2;
    int row = 3;
    int col = 3;
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int res[3][3];

    MinMax(arr, size, &min, &max);
    printf("Minimum: %d\nMaximum: %d", min, max);
    printf("\n");
    reverse(arr, size);
    printf("\n");
    count(arr, size, num);
    printf("\n");
    printf("%s\n", is_palindrome(arr, size) ? "Yes" : "No");
    printf("\n");
    compute_transpose(mat, row, col, res);
    printf("\n");
    printf("Sum: %d", sum(mat, 3, 3));

    return 0;
}