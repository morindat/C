# include <stdio.h>

void printarr(int rows, int cols, int *arr){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d ", arr[i * cols + j]);
        }
        printf("\n");
    }
}

void Checkloops(int size, int graph[size][size]){
    int hasloop = 0;

    for (int i = 0; i < size; i++){
        if (graph[i][i] = 1){
            hasloop = 1;
            printf("Loop detected at index: %d\n", i);
        }
    }
    if (!hasloop) {
        printf("No loops detected in the graph.\n");
    }
}

int main(){
    int n, m, p, q;

    printf("Please enter the number of rows and columns for A separated by space: ");
    scanf("%d %d", &n, &m);

    int A[n][m];

    printf("Please enter the number of rows and colums for B separated by space: ");
    scanf("%d %d", &p, &q);
    int B[p][q];
    
    int prod[n][q];

    printf("Enter the elements of A: \n");
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of B: \n");
    for(int i = 0; i < p; i++){
        for (int j = 0; j < q; j++){
            scanf("%d", &B[i][j]);
        }
    }

    // mult
    for (int i = 0; i < n; i++){
        for (int j = 0; j < q; j++){
            prod[i][j] = 0;
            for (int k = 0; k < m; k++){
                prod[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // trace of matrice
    int trace = 0;
    for (int i = 0; i < n; i++) {
        trace += A[i][i];
    }

    printf("The Product is: \n");
    printarr(n, q, &prod[0][0]);
    printf("The trace is: %d\n", trace);



    return 0;
}