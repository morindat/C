# include <stdio.h>


int main(){
    int n, sumdeg;
    printf("Please enter the number of vertices: ");
    scanf("%d", &n);

    int mat[n][n];

    printf("Enter the the adjaceny matrix (n * n): \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int multedge = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mat[i][j] > 1){
                multedge += mat[i][j] - 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (mat[i][i] > 0) {
            multedge += mat[i][i]; 
        }
    }

    for (int i = 0; i < n; i++){
        sumdeg = 0;
        for (int j = 0; j < n; j++){
            sumdeg += mat[i][j];
        }
        
        if (mat[i][i] > 1){
            sumdeg += mat[i][i];
        }

        printf("The degree of vertex %d is: %d\n", i, sumdeg);
    }

    printf("There are %d multiedges.\n", multedge);
    //printf("The sum of degrees is: %d\n", sumdeg);

    return 0;
}