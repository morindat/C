#include <stdio.h>
#include <stdlib.h>

// BFS using adjacency matrix representation
void bfsMatrix(int** matrix, int V, int startVertex) {
    if (!matrix || startVertex < 0 || startVertex >= V) {
        fprintf(stderr, "Error: Invalid matrix or start vertex\n");
        return;
    }

    int* visited = calloc(V, sizeof(int));
    if (!visited) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return;
    }

    int* queue = malloc(V * sizeof(int));
    if (!queue) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        free(visited);
        return;
    }

    int front = 0, rear = 0;
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS starting from %d: ", startVertex);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Iterate through all vertices (matrix row)
        for (int v = 0; v < V; ++v) {
            // If edge exists (matrix[current][v] == 1) and vertex not visited
            if (matrix[current][v] == 1 && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");

    free(visited);
    free(queue);
}

// DFS using adjacency matrix representation
void dfsMatrixUtil(int** matrix, int V, int node, int* visited) {
    visited[node] = 1;
    printf("%d ", node);

    // Iterate through all vertices (matrix row)
    for (int v = 0; v < V; ++v) {
        if (matrix[node][v] == 1 && !visited[v]) {
            dfsMatrixUtil(matrix, V, v, visited);
        }
    }
}

void dfsMatrix(int** matrix, int V) {
    if (!matrix || V <= 0) {
        fprintf(stderr, "Error: Invalid matrix\n");
        return;
    }

    int* visited = calloc(V, sizeof(int));
    if (!visited) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return;
    }

    printf("DFS (full graph): ");
    for (int v = 0; v < V; ++v) {
        if (!visited[v]) {
            dfsMatrixUtil(matrix, V, v, visited);
        }
    }
    printf("\n");

    free(visited);
}

// Shortest path using BFS with matrix
int shortestPathMatrix(int** matrix, int V, int src, int dest) {
    if (!matrix || src < 0 || dest < 0 || src >= V || dest >= V)
        return -1;
    if (src == dest) return 0;

    int* dist = malloc(V * sizeof(int));
    int* queue = malloc(V * sizeof(int));
    if (!dist || !queue) {
        free(dist);
        free(queue);
        return -1;
    }

    for (int i = 0; i < V; ++i) dist[i] = -1;

    int front = 0, rear = 0;
    dist[src] = 0;
    queue[rear++] = src;

    while (front < rear) {
        int u = queue[front++];

        // Iterate through all vertices in matrix row
        for (int v = 0; v < V; ++v) {
            if (matrix[u][v] == 1 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                if (v == dest) {
                    int answer = dist[v];
                    free(dist);
                    free(queue);
                    return answer;
                }
                queue[rear++] = v;
            }
        }
    }

    free(dist);
    free(queue);
    return -1;
}

// Print matrix
void printMatrix(int** matrix, int V) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V = 7;

    // Allocate adjacency matrix
    int** matrix = malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i) {
        matrix[i] = calloc(V, sizeof(int));
    }

    // Build same graph as your adjacency list version:
    // 0 -- 1 -- 2
    // |    |
    // 3    4 -- 5 -- 6
    
    // 0-1
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    
    // 1-2
    matrix[1][2] = 1;
    matrix[2][1] = 1;
    
    // 0-3
    matrix[0][3] = 1;
    matrix[3][0] = 1;
    
    // 1-4
    matrix[1][4] = 1;
    matrix[4][1] = 1;
    
    // 3-4
    matrix[3][4] = 1;
    matrix[4][3] = 1;
    
    // 4-5
    matrix[4][5] = 1;
    matrix[5][4] = 1;
    
    // 5-6
    matrix[5][6] = 1;
    matrix[6][5] = 1;

    printf("Graph with V=%d vertices\n\n", V);
    printMatrix(matrix, V);
    printf("\n");

    bfsMatrix(matrix, V, 0);
    dfsMatrix(matrix, V);

    // Test shortest paths
    printf("Shortest distance 0 -> 4 = %d\n", shortestPathMatrix(matrix, V, 0, 4));
    printf("Shortest distance 0 -> 2 = %d\n", shortestPathMatrix(matrix, V, 0, 2));
    printf("Shortest distance 0 -> 5 = %d\n", shortestPathMatrix(matrix, V, 0, 5));
    printf("Shortest distance 0 -> 6 = %d\n", shortestPathMatrix(matrix, V, 0, 6));

    // Cleanup
    for (int i = 0; i < V; ++i) free(matrix[i]);
    free(matrix);

    return 0;
}
