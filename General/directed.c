# include <stdio.h>

int main(){
    int n;
    printf("Please enter the number of vertices: ");
    scanf("%d", &n);

    int mat[n][n];

    printf("Enter the the adjaceny matrix (n * n): \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int isUndirected = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(mat[i][j] != mat[j][i]){
                isUndirected = 0;
                break;
            }
        }
        if (!isUndirected) {
            break;
        }
    }

    if (isUndirected) {
        printf("The graph is undirected.\n");
    } else {
        printf("The graph is directed.\n");
    }

    return 0;
}