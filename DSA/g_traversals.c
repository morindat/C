# include <stdio.h>
# include <stdlib.h>

void printMatrix(int** matrix, int V){
    printf("Adjacency Matrix\n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void bfs(int** matrix, int V, int startVertex){
    if (!matrix || V <= 0 || startVertex < 0 || startVertex >= V) {
        fprintf(stderr, "Error: Invalid matrix or start vertex\n");
        return;
    }

    int* visited = calloc(V, sizeof(int));
    int* queue = malloc(V * sizeof(int));
    if (!visited || !queue) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        free(visited);
        free(queue);
        return;
    }

    int rear = 0, front = 0;
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS Traversal from vertex %d: ", startVertex);

    while(front < rear){
        int current = queue[front++];
        printf("%d ", current);

        for(int v = 0; v < V; v++){
            if (matrix[current][v] == 1 && !visited[v]){
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
    
    free(visited);
    free(queue);
}

void dfsUtil(int** matrix, int V, int node, int* visited){
    visited[node] = 1;
    printf("%d ", node);

    for (int v = 0; v < V; v++){
        if (matrix[node][v] == 1 && !visited[v]){
            dfsUtil(matrix, V, v, visited);
        }
    }
}

void dfs(int** matrix, int V){
    if (!matrix || V <= 0) {
        fprintf(stderr, "Error: Invalid matrix or V\n");
        return;
    }
    
    int* visited = calloc(V, sizeof(int));
    if (!visited) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return;
    }

    printf("DFS Traversal (full graph): ");
    for (int v = 0; v < V; ++v) {
        if (!visited[v]) {
            dfsUtil(matrix, V, v, visited);
        }
    }
    printf("\n");
    
    free(visited);
}

int main(){
    int V = 5;

    int** matrix = malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++){
        matrix[i] = calloc(V, sizeof(int));
    }

    // 0-1
    matrix[0][1] = 1;
    matrix[1][0] = 1;

    // 1-3
    matrix[1][3] = 1;
    matrix[3][1] = 1;

    // 0-2
    matrix[0][2] = 1;
    matrix[2][0] = 1;

    // 2-4
    matrix[2][4] = 1;
    matrix[4][2] = 1;

    // 3-4
    matrix[3][4] = 1;
    matrix[4][3] = 1;


    // tesing the print function?
    printMatrix(matrix, V);
    printf("\n");

    // testing bfs
    bfs(matrix, V, 0);
    dfs(matrix, V);
}
