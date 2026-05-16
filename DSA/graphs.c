#include <stdio.h>
#include <stdlib.h>

// Graphs Initialization
// Node and Graph struct

typedef struct Node {
  int neighbour; // neighbour for each vertices
  struct Node *next;
} Node;

typedef struct Graph {
  int vCount;     // No of vertices in the list
  Node **adjList; // A linked list for edges/connections
} Graph;

// Initializing a graph with a number of vertices expected in that graph

Graph *createGraph(int no_of_vertices) {
  if (no_of_vertices <= 0) {
    fprintf(stderr, "Error (createGraph): invalid vertex count (%d)\n", no_of_vertices);
    return NULL;
  }

  Graph *graph = malloc(sizeof(Graph));
  if (!graph) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    return NULL;
  }

  graph->vCount = no_of_vertices;

  // allocate memory to adj list

  graph->adjList = calloc(no_of_vertices, sizeof(Node*));
  if (graph->adjList == NULL) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    free(graph);
    return NULL;
  }

  return graph;
}

// Adding edges to a graph

Node *createNode(int vertex) {
  Node *newNode = malloc(sizeof(Node));
  if (!newNode) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    return NULL;
  }

  newNode->neighbour = vertex;
  newNode->next = NULL;

  return newNode;
}

void addEdge(Graph *graph, int u, int v) {
  // Edge checks for a graph with vertices 0 to n - 1;

  if (!graph || u < 0 || v < 0 || u >= graph->vCount || v >= graph->vCount) {
    fprintf(stderr, "addEdge: invalid vertex index\n");
    return;
  }

  /* allocate both nodes first to avoid partial updates on allocation failure */

  Node *nodeV = createNode(v);
  Node *nodeU = createNode(u);
  if (!nodeV || !nodeU) {
    free(nodeV);
    free(nodeU);
    fprintf(stderr, "addEdge: allocation failed\n");
    return;
  }

  nodeV->next = graph->adjList[u];
  graph->adjList[u] = nodeV;

  // For undirected
  nodeU->next = graph->adjList[v];
  graph->adjList[v] = nodeU;
}

// Printing

void printGraph(Graph *graph) {
  if (!graph) {
    fprintf(stderr, "printGraph: graph is NULL\n");
    return;
  }

  for (int vertex = 0; vertex < graph->vCount; vertex++) {
    printf("%d : ", vertex);

    Node *current = graph->adjList[vertex];

    while (current != NULL) {
      printf("%d -> ", current->neighbour);
      current = current->next;
    }

    printf("NULL\n");
  }
}

// Destroy graph

void destroyGraph(Graph *graph) {
  if (!graph)
    return;

  for (int i = 0; i < graph->vCount; i++) {
    Node *current = graph->adjList[i];
    while (current != NULL) {
      Node *temp = current;
      current = current->next;
      free(temp);
    }
  }

  free(graph->adjList);
  free(graph);
}

void bfs(Graph *graph, int startVertex) {
  if (!graph)
    return;

  // Allocate memory for visited array
  int *visited = calloc(graph->vCount, sizeof(int));
  if (!visited) {
    fprintf(stderr, "bfs: allocation failed\n");
    return;
  }

  // Initialize the queue for bfs
  int *que = malloc(graph->vCount * sizeof(int));
  if (!que) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    free(visited);
    return;
  }

  int front = 0;
  int rear = 0;

  // Push the startVertex into the queue and mark it visited
  que[rear++] = startVertex;
  visited[startVertex] = 1;

  printf("BFS from %d: ", startVertex);

  while (front < rear) {
    // Print it 
    int current = que[front++];
    printf("%d ", current);

    Node *temp = graph->adjList[current];
    while (temp) {
      int neigh = temp->neighbour;
      if (!visited[neigh]) {
        visited[neigh] = 1;
        que[rear++] = neigh;
      }
      temp = temp->next;
    }
  }

  printf("\n");

  free(visited);
  free(que);
}

void dfsUtil(Graph* graph, int node, int* visited){
    visited[node] = 1;
    printf("%d ", node);

    for (Node* temp = graph->adjList[node]; temp != NULL; temp = temp->next){
        int neigh = temp->neighbour;
        if (!visited[neigh]){
            dfsUtil(graph, neigh, visited);
        }
    }
}

void dfs(Graph* graph){
    if(!graph){
        fprintf(stderr, "Error: Graph not allocated\n");
        return;
    }

    int *visited = calloc(graph->vCount, sizeof(int));
    if (!visited) {
        fprintf(stderr, "dfs: allocation failed\n");
        return;
    }

    printf("DFS (full graph): ");
    for (int v = 0; v < graph->vCount; v++) {
        if (!visited[v]) {
            dfsUtil(graph, v, visited);
        }
    }
    printf("\n");
    free(visited);

}

int main() {
  // Create a graph with 5 vertices: 0,1,2,3,4

  Graph *graph = createGraph(5);
  if (!graph)
    return 1; // creation failed

  // Build this graph:
  // 0 -- 1 -- 2
  // |    |
  // 3    4

  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 4);

  // Print graph structure
  printf("Graph adjacency list:\n");
  printGraph(graph);

  bfs(graph, 0);
  dfs(graph);

  // Cleanup
  destroyGraph(graph);

  return 0;
}