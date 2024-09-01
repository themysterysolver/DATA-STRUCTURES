#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct Graph {
    int vertices;
    Node** adjacencyList;
} Graph;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (Node**)malloc(vertices * sizeof(Node*));

    
    for (int i = 0; i < vertices; i++)
        graph->adjacencyList[i] = NULL;

    return graph;
}


void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

  
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}


void BFS(Graph* graph, int startVertex) {
    
}


void DFSUtil(Graph* graph, int vertex, int visited[]) {
    
}

void DFS(Graph* graph, int startVertex) {
    
}


void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Create Map\n");
    printf("2. Breadth-First Search (BFS)\n");
    printf("3. Depth-First Search (DFS)\n");
    printf("4. Exit\n");
}

int main() {
    Graph* graph = NULL;
    int choice, vertices, src, dest, startVertex;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create Map
                printf("Enter the number of vertices: ");
                scanf("%d", &vertices);
                graph = createGraph(vertices);

                printf("Enter the edges (enter -1 -1 to stop):\n");
                while (1) {
                    printf("Enter edge (src dest): ");
                    scanf("%d %d", &src, &dest);

                    if (src == -1 && dest == -1)
                        break;

                    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
                        printf("Invalid edge! Try again.\n");
                    } else {
                        addEdge(graph, src, dest);
                    }
                }
                break;

            case 2:
                // Breadth-First Search (BFS)
                if (graph == NULL) {
                    printf("Create a map first!\n");
                } else {
                    printf("Enter the starting vertex for BFS: ");
                    scanf("%d", &startVertex);
                    BFS(graph, startVertex);
                }
                break;

            case 3:
                // Depth-First Search (DFS)
                if (graph == NULL) {
                    printf("Create a map first!\n");
                } else {
                    printf("Enter the starting vertex for DFS: ");
                    scanf("%d", &startVertex);
                    DFS(graph, startVertex);
                }
                break;

            case 4:
                // Exit
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
