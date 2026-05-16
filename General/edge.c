#include <stdio.h>

int main() {
    int n; // Number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Declare adjacency matrix
    int adjMatrix[n][n];

    // Input adjacency matrix element-wise
    printf("Enter the adjacency matrix (row-wise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Count total number of edges
    int totalEdges = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Only consider upper triangular part
            if (adjMatrix[i][j] == 1) {
                totalEdges++;
            }
        }
    }

    // Calculate sum of degrees
    int sumOfDegrees = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumOfDegrees += adjMatrix[i][j];
        }
    }

    // Output the results
    printf("The total number of edges in the graph is: %d\n", totalEdges);
    printf("The sum of the degrees of all vertices in the graph is: %d\n", sumOfDegrees);

    // Verify the Handshaking Lemma
    if (sumOfDegrees == 2 * totalEdges) {
        printf("Verification: The sum of degrees equals twice the total number of edges.\n");
    } else {
        printf("Error: The sum of degrees does not match twice the total number of edges.\n");
    }

    return 0;
}