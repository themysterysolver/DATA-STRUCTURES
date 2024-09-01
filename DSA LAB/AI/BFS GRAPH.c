#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
int verticesCount = 0;
bool visited[MAX_SIZE];

void addEdge(int startVertex, int endVertex) {
    if (startVertex >= verticesCount || endVertex >= verticesCount || startVertex < 0 || endVertex < 0) {
        printf("Invalid vertex!\n");
        return;
    }
    adjacencyMatrix[startVertex][endVertex] = 1;
    adjacencyMatrix[endVertex][startVertex] = 1; // Uncomment for undirected graph
}

void BFS(int startVertex) {
    int queue[MAX_SIZE];
    int front = -1, rear = -1;

    printf("BFS Traversal: ");
    visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        for (int i = 0; i < verticesCount; i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    // Adding vertices (0, 1, 2, 3, 4)
    verticesCount = 5;

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < verticesCount; i++) {
        for (int j = 0; j < verticesCount; j++) {
            adjacencyMatrix[i][j] = 0;
        }
        visited[i] = false;
    }

    // Adding edges between vertices
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    // Perform BFS from vertex 0
    BFS(0);
    printf("\n");

    return 0;
}
