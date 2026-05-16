# include <stdio.h>

int Countloop(int size, int graph[size][size]){
    int count = 0;

    for (int i = 0; i < size; i++){
        if (graph[i][i] == 1){
            count++; 
        }
    }
    return count;
}

int main(){
    int size;
    printf("Please enter the size of the matrix: ");
    scanf("%d", &size);

    int graph[size][size];

    printf("Please enter the adjaceny of the matrix (3 * 3): \n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    int ans = Countloop(size, graph);
    printf("%d loops detected!\n", ans);


    return 0;
}