#include <stdio.h>

#define MAX 100

int adj[MAX][MAX]; // adjacency matrix
int visited[MAX];

void DFS(int vertex, int n) {
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] && !visited[i]) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter %d edges (0-indexed vertex pairs):\n", e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, n);
            count++;
        }
    }

    printf("Number of connected components: %d\n", count);

    return 0;
}
