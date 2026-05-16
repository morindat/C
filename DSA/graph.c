# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph{
    int vertices;
    Node** adjList;
} Graph;

Graph* createGraph(int vertices){
    if (vertices <= 0){
        fprintf(stderr, "Error: Vertices must be >= 1\n");
        return NULL;
    }

    Graph* graph = malloc (sizeof(Graph));
    if (!graph){
        fprintf(stderr, "Error: Memory allocation failed (createGraph)\n");
        return NULL;
    }

    graph->vertices = vertices;

    graph->adjList = calloc(vertices, sizeof(Node*));
    if (!graph->adjList){
        fprintf(stderr, "Error: Memory allocation failed (createGraph)\n");
        free(graph);
        return NULL;
    }

    return graph;
}

Node* createNode(int nodeVal){
    Node* newNode = malloc(sizeof(Node));
    if (!newNode){
        fprintf(stderr, "Error: Memory allocation failed (createNode)\n");
        return NULL;
    }

    newNode->vertex = nodeVal;
    newNode->next = NULL;

    return newNode;
}

void addEdge(Graph* graph, int now, int next){
    if(!graph || next < 0 || now < 0 || next >= graph->vertices || now >= graph->vertices){
        fprintf(stderr, "Error: Invalid graph or indexing (addEdge)\n");
        return;
    }

    // Create nodes with the values
    Node* nodeV = createNode(next);
    Node* nodeU = createNode(now);
    if (!nodeV || !nodeU){
        fprintf(stderr, "Error: Could not create nodes (addEdge)\n");
        free(nodeU);
        free(nodeV);
        return;
    }

    nodeV->next = graph->adjList[now];
    graph->adjList[now] = nodeV;

    // For undirected
    nodeU->next = graph->adjList[next];
    graph->adjList[next] = nodeU;
}

void printGraph(Graph* graph){
    if (!graph){
        fprintf(stderr, "Error: Graph does not exist (printGraph)\n");
        return;
    }

    for (int vertex = 0; vertex < graph->vertices; vertex++){
        printf("%d : ", vertex);

        Node* temp = graph->adjList[vertex];
        while (temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void destroyGraph(Graph* graph){
    if (!graph){
        fprintf(stderr, "Error: Nothing to destroy, graph is non existent (destroyGraph)\n");
        return;
    }

    for (int i = 0; i < graph->vertices; i++){
        Node* temp = graph->adjList[i];
        while (temp){
            Node* current = temp;
            temp = temp->next;
            free(current);
        }
    }

    free(graph->adjList);
    free(graph);
}

void bfs(Graph* graph, int startingVetex){
    if(!graph){
        fprintf(stderr, "Error: Graph does not exist (bfs)\n");
        return;
    }

    int* visitedArray = calloc(graph->vertices, sizeof(int));
    if(!visitedArray){
        fprintf(stderr, "Error: Memory allocation error (visitedArray)\n");
        return;
    }

    int* que = malloc(graph->vertices * sizeof(int));
    if(!que){
        fprintf(stderr, "Error: Memory allocation error (que)\n");
        return;
    }

    int front = 0;
    int rear = 0;
    visitedArray[startingVetex] = 1;
    que[rear++] = startingVetex;

    printf("BFS starting from %d : ", startingVetex);

    while (front < rear){
        int now = que[front++];
        printf("%d ", now);

        Node* temp = graph->adjList[now];
        while (temp){
            int neighbour = temp->vertex;
            if(!visitedArray[neighbour]){
                que[rear++] = neighbour;
                visitedArray[neighbour] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visitedArray);
    free(que);
}

void dfsUtil(Graph* graph, int node, int* visited){
    visited[node] = 1;
    printf("%d ", node);

    for(Node* temp = graph->adjList[node]; temp != NULL; temp = temp->next){
        int neigh = temp->vertex;
        if (!visited[neigh]){
            dfsUtil(graph, neigh, visited);
        }
    }
}

void dfs(Graph* graph){
    if(!graph){
        fprintf(stderr, "Error: graph not exist (dfs)\n");
        return;
    }

    int* visited = calloc(graph->vertices, sizeof(int));
    if(!visited){
        fprintf(stderr, "Error: Memory allocation failed (visited(dfs))\n");
        return;
    }

    printf("DFS (full graph): ");
    for (int i = 0; i < graph->vertices; i++){
        if(!visited[i])
            dfsUtil(graph, i, visited);
    }

    printf("\n");
    free(visited);
}

int shortestPathBFS(Graph* graph, int src, int dest) {
    if (!graph || src < 0 || dest < 0 || src >= graph->vertices || dest >= graph->vertices)
        return -1;
    if (src == dest) return 0;

    int V = graph->vertices;
    int *dist = malloc(V * sizeof(int));
    int *queue = malloc(V * sizeof(int));
    if (!dist || !queue) { free(dist); free(queue); return -1; }

    for (int i = 0; i < V; ++i) dist[i] = -1;
    int front = 0, rear = 0;
    dist[src] = 0;
    queue[rear++] = src;

    while (front < rear) {
        int now = queue[front++];
        for (Node *temp = graph->adjList[now]; temp; temp = temp->next) {
            int next = temp->vertex;
            if (dist[next] == -1) {
                dist[next] = dist[now] + 1;
                if (next == dest) {
                    int ans = dist[next];
                    free(dist); 
                    free(queue);
                    return ans;
                }
                queue[rear++] = next;
            }
        }
    }

    free(dist); free(queue);
    return -1;
}

// Returns 1 if cycle detected, 0 otherwise
int hasCycleUtil(Graph* graph, int node, int* visited, int parent) {
    visited[node] = 1;
    
    for (Node* tmp = graph->adjList[node]; tmp; tmp = tmp->next) {
        int neighbor = tmp->vertex;
        if (!visited[neighbor]) {
            if (hasCycleUtil(graph, neighbor, visited, node))
                return 1;
        } else if (neighbor != parent) {
            // Found a back edge (visited neighbor that's not the parent)
            return 1;
        }
    }
    return 0;
}

int hasCycleUndirected(Graph* graph) {
    if (!graph) return 0;
    int* visited = calloc(graph->vertices, sizeof(int));
    if (!visited) return -1; // error
    
    for (int v = 0; v < graph->vertices; ++v) {
        if (!visited[v]) {
            if (hasCycleUtil(graph, v, visited, -1)) {
                free(visited);
                return 1; // cycle found
            }
        }
    }
    free(visited);
    return 0; // no cycle
}

int main(){
    Graph* graph = createGraph(7);
    if (!graph) return -1;

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);

    printf("Graph adjacency list:\n");
    printGraph(graph);

    bfs(graph, 0);
    dfs(graph);

    printf("Shortest Distance in 0 -> 6 = %d\n", shortestPathBFS(graph, 0, 6));

    destroyGraph(graph);

    return 0;
}