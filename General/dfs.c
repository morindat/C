#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
int visited[MAX_VERTICES];
int path[MAX_VERTICES]; // to store DFS path
int path_index = 0;
int last_vertex = -1;

void DFS(int vertex, int n) {
    visited[vertex] = 1;
    path[path_index++] = vertex;
    last_vertex = vertex;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] && !visited[i]) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter %d edges (as pairs of vertices, 0-indexed):\n", e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // because it’s an undirected tree
    }

    int start;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal Path: ");
    DFS(start, n);

    for (int i = 0; i < path_index; i++) {
        printf("%d ", path[i]);
    }

    printf("\nLast Vertex Visited in DFS: %d\n", last_vertex);

    return 0;
}
