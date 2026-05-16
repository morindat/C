#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================================
// PROBLEM 1: DFS TRAVERSAL
// ============================================================================
// Approach: Recursive DFS starting from a vertex
// - Mark current vertex as visited and print it
// - Recursively visit all unvisited neighbors
// - For disconnected graphs, call from each unvisited vertex
// Time: O(V + E), Space: O(V) for visited array + O(V) for recursion stack

void dfsUtil(int** matrix, int V, int node, int* visited) {
    visited[node] = 1;
    printf("%d ", node);
    
    for (int v = 0; v < V; ++v) {
        if (matrix[node][v] == 1 && !visited[v]) {
            dfsUtil(matrix, V, v, visited);
        }
    }
}

void dfsTraversal(int** matrix, int V) {
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

// ============================================================================
// PROBLEM 2: BFS TRAVERSAL
// ============================================================================
// Approach: Iterative BFS using a queue
// - Enqueue start vertex, mark as visited
// - Dequeue vertex, process all unvisited neighbors, enqueue them
// - Continue until queue is empty
// - For disconnected graphs, call from each unvisited vertex
// Time: O(V + E), Space: O(V) for visited array and queue

void bfsTraversal(int** matrix, int V, int startVertex) {
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
    
    int front = 0, rear = 0;
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    
    printf("BFS Traversal from vertex %d: ", startVertex);
    
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        
        for (int v = 0; v < V; ++v) {
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

// ============================================================================
// PROBLEM 3: CYCLE DETECTION (Undirected Graph)
// ============================================================================
// Approach: DFS with parent tracking
// - For each vertex, recursively visit unvisited neighbors
// - If we encounter a visited vertex that is NOT the parent, it's a back edge
// - Back edge = cycle detected
// Note: For undirected graphs, we track parent to avoid immediate backtrack
// Time: O(V + E), Space: O(V)

int hasCycleUtil(int** matrix, int V, int node, int parent, int* visited) {
    visited[node] = 1;
    
    for (int v = 0; v < V; ++v) {
        if (matrix[node][v] == 1) {
            if (!visited[v]) {
                if (hasCycleUtil(matrix, V, v, node, visited))
                    return 1;
            } else if (v != parent) {
                // Found a back edge (visited vertex that's not parent)
                return 1;
            }
        }
    }
    return 0;
}

int cycleDetectionUndirected(int** matrix, int V) {
    if (!matrix || V <= 0) {
        fprintf(stderr, "Error: Invalid matrix or V\n");
        return -1;
    }
    
    int* visited = calloc(V, sizeof(int));
    if (!visited) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return -1;
    }
    
    for (int v = 0; v < V; ++v) {
        if (!visited[v]) {
            if (hasCycleUtil(matrix, V, v, -1, visited)) {
                free(visited);
                return 1; // Cycle found
            }
        }
    }
    
    free(visited);
    return 0; // No cycle
}

// ============================================================================
// PROBLEM 4: SHORTEST PATH (BFS)
// ============================================================================
// Approach: Standard BFS with distance tracking
// - Maintain dist[] array initialized to -1 (unvisited)
// - Start from src with dist[src] = 0
// - For each vertex, update distance of unvisited neighbors
// - Return early when destination is discovered (first discovery = shortest)
// Time: O(V + E), Space: O(V)

int shortestPathBFS(int** matrix, int V, int src, int dest) {
    if (!matrix || V <= 0 || src < 0 || src >= V || dest < 0 || dest >= V) {
        fprintf(stderr, "Error: Invalid matrix or vertices\n");
        return -1;
    }
    
    if (src == dest) return 0;
    
    int* dist = malloc(V * sizeof(int));
    int* queue = malloc(V * sizeof(int));
    if (!dist || !queue) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        free(dist);
        free(queue);
        return -1;
    }
    
    // Initialize distances to -1 (unvisited)
    for (int i = 0; i < V; ++i) dist[i] = -1;
    
    int front = 0, rear = 0;
    dist[src] = 0;
    queue[rear++] = src;
    
    while (front < rear) {
        int u = queue[front++];
        
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
    return -1; // Destination unreachable
}

// ============================================================================
// PROBLEM 5: SPARSITY CHECK & DEGREE CALCULATION
// ============================================================================
// Approach: Single pass through matrix
// - Count total non-zero entries and degree for each vertex
// - Graph is sparse if: count_of_1s < n²/4
// - Return array: res[0..n-1] = degrees, res[n] = sparsity flag (1=sparse, 0=dense)
// Time: O(V²), Space: O(V)

int* sparsityCheckAndDegree(int** matrix, int n) {
    if (!matrix || n <= 0) {
        fprintf(stderr, "Error: Invalid matrix or n\n");
        return NULL;
    }
    
    int* res = malloc((n + 1) * sizeof(int));
    if (!res) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    
    // Initialize degrees
    for (int i = 0; i < n; ++i) {
        res[i] = 0;
    }
    
    // Count non-zero entries and calculate degrees
    int nonZeroCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
                res[i]++; // Increment degree of vertex i
            }
        }
    }
    
    // Check sparsity: non-zero count < n²/4
    int threshold = (n * n) / 4;
    res[n] = (nonZeroCount < threshold) ? 1 : 0;
    
    return res;
}

// ============================================================================
// PROBLEM 6: CONNECTED COMPONENTS
// ============================================================================
// Approach: DFS from each unvisited vertex
// - Each DFS call explores one connected component
// - Count number of DFS calls = number of connected components
// Time: O(V + E), Space: O(V)

int connectedComponentsUtil(int** matrix, int V, int node, int* visited) {
    visited[node] = 1;
    int count = 1;
    
    for (int v = 0; v < V; ++v) {
        if (matrix[node][v] == 1 && !visited[v]) {
            count += connectedComponentsUtil(matrix, V, v, visited);
        }
    }
    return count;
}

int countConnectedComponents(int** matrix, int V) {
    if (!matrix || V <= 0) {
        fprintf(stderr, "Error: Invalid matrix or V\n");
        return -1;
    }
    
    int* visited = calloc(V, sizeof(int));
    if (!visited) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return -1;
    }
    
    int components = 0;
    for (int v = 0; v < V; ++v) {
        if (!visited[v]) {
            connectedComponentsUtil(matrix, V, v, visited);
            components++;
        }
    }
    
    free(visited);
    return components;
}

// ============================================================================
// PROBLEM 7: GRAPH TRANSPOSE (for directed graphs)
// ============================================================================
// Approach: Create new matrix with reversed edges
// - For each edge (u, v) in original, add edge (v, u) in transposed
// - Transpose of undirected graph is the same graph
// - Useful for directed graph analysis
// Time: O(V²), Space: O(V²)

int** transposeGraph(int** matrix, int V) {
    if (!matrix || V <= 0) {
        fprintf(stderr, "Error: Invalid matrix or V\n");
        return NULL;
    }
    
    int** transposed = malloc(V * sizeof(int*));
    if (!transposed) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    
    for (int i = 0; i < V; ++i) {
        transposed[i] = calloc(V, sizeof(int));
        if (!transposed[i]) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            return NULL;
        }
    }
    
    // Transpose: matrix[i][j] -> transposed[j][i]
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    return transposed;
}

// ============================================================================
// PROBLEM 8: DEGREE DISTRIBUTION (Max and Min degree)
// ============================================================================
// Approach: Single pass through all vertices
// - For each vertex, count its degree (number of adjacent vertices)
// - Track max and min degrees
// Time: O(V²), Space: O(V)

void degreeDistribution(int** matrix, int V) {
    if (!matrix || V <= 0) {
        fprintf(stderr, "Error: Invalid matrix or V\n");
        return;
    }
    
    int* degree = malloc(V * sizeof(int));
    if (!degree) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return;
    }
    
    // Calculate degree for each vertex
    for (int i = 0; i < V; ++i) {
        degree[i] = 0;
        for (int j = 0; j < V; ++j) {
            if (matrix[i][j] == 1) {
                degree[i]++;
            }
        }
    }
    
    // Find max and min degree
    int maxDegree = degree[0];
    int minDegree = degree[0];
    int maxVertex = 0;
    int minVertex = 0;
    
    for (int i = 1; i < V; ++i) {
        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
            maxVertex = i;
        }
        if (degree[i] < minDegree) {
            minDegree = degree[i];
            minVertex = i;
        }
    }
    
    printf("Degree Distribution:\n");
    for (int i = 0; i < V; ++i) {
        printf("Vertex %d: degree = %d\n", i, degree[i]);
    }
    printf("Max degree: %d (vertex %d)\n", maxDegree, maxVertex);
    printf("Min degree: %d (vertex %d)\n\n", minDegree, minVertex);
    
    free(degree);
}

// ============================================================================
// PROBLEM 9: PATH EXISTENCE CHECK
// ============================================================================
// Approach: DFS to find if path exists between two vertices
// - Start DFS from src
// - If we reach dest, return 1
// - If DFS completes without reaching dest, return 0
// Time: O(V + E), Space: O(V)

int pathExistsUtil(int** matrix, int V, int current, int dest, int* visited) {
    if (current == dest) return 1;
    
    visited[current] = 1;
    
    for (int v = 0; v < V; ++v) {
        if (matrix[current][v] == 1 && !visited[v]) {
            if (pathExistsUtil(matrix, V, v, dest, visited))
                return 1;
        }
    }
    return 0;
}

int pathExists(int** matrix, int V, int src, int dest) {
    if (!matrix || V <= 0 || src < 0 || src >= V || dest < 0 || dest >= V) {
        fprintf(stderr, "Error: Invalid matrix or vertices\n");
        return -1;
    }
    
    if (src == dest) return 1;
    
    int* visited = calloc(V, sizeof(int));
    if (!visited) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return -1;
    }
    
    int result = pathExistsUtil(matrix, V, src, dest, visited);
    free(visited);
    return result;
}

// ============================================================================
// PROBLEM 10: ALL-PAIRS SHORTEST PATH (Floyd-Warshall)
// ============================================================================
// Approach: Dynamic programming
// - For each pair (i, j), try all intermediate vertices k
// - If path via k is shorter, update distance
// - Initialize: dist[i][j] = matrix[i][j], dist[i][i] = 0
// Time: O(V³), Space: O(V²)

int** allPairsShortestPath(int** matrix, int V) {
    if (!matrix || V <= 0) {
        fprintf(stderr, "Error: Invalid matrix or V\n");
        return NULL;
    }
    
    // Create distance matrix
    int** dist = malloc(V * sizeof(int*));
    if (!dist) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    
    for (int i = 0; i < V; ++i) {
        dist[i] = malloc(V * sizeof(int));
        if (!dist[i]) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            return NULL;
        }
        for (int j = 0; j < V; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (matrix[i][j] == 1) {
                dist[i][j] = 1;
            } else {
                dist[i][j] = 999; // Infinity (no edge)
            }
        }
    }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    return dist;
}

void printAllPairsShortestPath(int** dist, int V) {
    printf("All-Pairs Shortest Path Matrix:\n");
    printf("   ");
    for (int j = 0; j < V; ++j) printf("%3d ", j);
    printf("\n");
    
    for (int i = 0; i < V; ++i) {
        printf("%2d:", i);
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == 999) {
                printf("  X ");
            } else {
                printf("%3d ", dist[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// ============================================================================
// MAIN: TEST ALL PROBLEMS
// ============================================================================

void printMatrix(int** matrix, int V, const char* title) {
    printf("%s:\n", title);
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int V = 5;
    
    // Allocate and initialize matrix
    int** matrix = malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i) {
        matrix[i] = calloc(V, sizeof(int));
    }
    
    // Build test graph
    // 0 -- 1 -- 2
    // |    |
    // 3    4
    matrix[0][1] = 1; matrix[1][0] = 1;
    matrix[1][2] = 1; matrix[2][1] = 1;
    matrix[0][3] = 1; matrix[3][0] = 1;
    matrix[1][4] = 1; matrix[4][1] = 1;
    
    printMatrix(matrix, V, "Test Graph (Adjacency Matrix)");
    
    // Problem 1: DFS
    printf("=== PROBLEM 1: DFS TRAVERSAL ===\n");
    dfsTraversal(matrix, V);
    printf("\n");
    
    // Problem 2: BFS
    printf("=== PROBLEM 2: BFS TRAVERSAL ===\n");
    bfsTraversal(matrix, V, 0);
    printf("\n");
    
    // Problem 3: Cycle Detection
    printf("=== PROBLEM 3: CYCLE DETECTION ===\n");
    int hasCycle = cycleDetectionUndirected(matrix, V);
    printf("Graph has cycle: %s\n\n", hasCycle ? "YES" : "NO");
    
    // Problem 4: Shortest Path
    printf("=== PROBLEM 4: SHORTEST PATH (BFS) ===\n");
    int path = shortestPathBFS(matrix, V, 0, 4);
    printf("Shortest distance 0 -> 4: %d\n\n", path);
    
    // Problem 5: Sparsity Check
    printf("=== PROBLEM 5: SPARSITY CHECK & DEGREE ===\n");
    int* result = sparsityCheckAndDegree(matrix, V);
    if (result) {
        for (int i = 0; i < V; ++i) {
            printf("Vertex %d: degree = %d\n", i, result[i]);
        }
        printf("Graph is %s (threshold = %d)\n\n", 
               result[V] ? "SPARSE" : "DENSE", (V * V) / 4);
        free(result);
    }
    
    // Problem 6: Connected Components
    printf("=== PROBLEM 6: CONNECTED COMPONENTS ===\n");
    int components = countConnectedComponents(matrix, V);
    printf("Number of connected components: %d\n\n", components);
    
    // Problem 7: Graph Transpose
    printf("=== PROBLEM 7: GRAPH TRANSPOSE ===\n");
    int** transposed = transposeGraph(matrix, V);
    printMatrix(transposed, V, "Transposed Graph");
    
    // Problem 8: Degree Distribution
    printf("=== PROBLEM 8: DEGREE DISTRIBUTION ===\n");
    degreeDistribution(matrix, V);
    
    // Problem 9: Path Existence
    printf("=== PROBLEM 9: PATH EXISTENCE CHECK ===\n");
    int exists = pathExists(matrix, V, 0, 2);
    printf("Path exists from 0 to 2: %s\n\n", exists ? "YES" : "NO");
    
    // Problem 10: All-Pairs Shortest Path
    printf("=== PROBLEM 10: ALL-PAIRS SHORTEST PATH ===\n");
    int** apsp = allPairsShortestPath(matrix, V);
    printAllPairsShortestPath(apsp, V);
    
    // Cleanup
    for (int i = 0; i < V; ++i) {
        free(matrix[i]);
        free(transposed[i]);
        free(apsp[i]);
    }
    free(matrix);
    free(transposed);
    free(apsp);
    
    return 0;
}
