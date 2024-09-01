#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 50
#define INVALID_VERTEX -1

// Define constants for menu options
#define OPTION_BFS 1
#define OPTION_DFS 2
#define OPTION_EXIT 3

typedef struct Graph_t {
    int v; // no of vertices
    bool adj[Max][Max];
} Graph;

typedef bool BoolArray[Max];

Graph *Graph_create(int v) {
    Graph *g = malloc(sizeof(Graph));
    g->v = v;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            g->adj[i][j] = false;
        }
    }
    return g;
}

void Graph_destroy(Graph *g) {
    free(g);
}

void Graph_edge(Graph *g, int w, int k) {
    g->adj[w][k] = true;
    g->adj[k][w] = true;
}

void graph_BFS(Graph *g, int s) {
    BoolArray visited = {false};
    int queue[Max];
    int front = 0, rear = 0;
    visited[s] = true;
    queue[rear++] = s;
    while (front != rear) {
        s = queue[front++];
        printf("%d  ", s);
        for (int adjacent = 0; adjacent < g->v; adjacent++) {
            if (g->adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

void graph_DFS(Graph *g, int st) {
    int stack[Max];
    int top = -1;
    BoolArray visited = {false};
    visited[st] = true;
    stack[++top] = st;
    while (top != -1) {
        st = stack[top--];
        printf("%d ", st);
        for (int adjacent = 0; adjacent < g->v; adjacent++) {
            if (g->adj[st][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                stack[++top] = adjacent;
            }
        }
    }
}

void readGraph(Graph *g) {
    
    int t=1;
    printf("Enter the edges  in the(format: v1 v2):\n");
    while(t){
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        Graph_edge(g, vertex1, vertex2);
        printf("Enter 1 to continue insertion and 0 to exit from the matrix:");
        scanf("%d",&t);
    }
}

int displayMenu() {
    int choice;
    printf("\nMenu :\n");
    printf("1. BFS Traversal(option-1)\n");
    printf("2. DFS Traversal(option-2)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int vertices;
    printf("Enter number of vertices in the graph!!: ");
    scanf("%d", &vertices);

    Graph *g = Graph_create(vertices);
    readGraph(g);

    int startVertex;
    printf("Enter  starting vertex for traversal: ");
    scanf("%d", &startVertex);

    int option;
    do {
        printf("\n graph:\n");
        for (int i = 0; i < g->v; i++) {
            for (int j = 0; j < g->v; j++) {
                printf("%d ", g->adj[i][j]);
            }
            printf("\n");
        }

        option = displayMenu();

        switch (option) {
            case OPTION_BFS:
                printf("BFS Traversal(option-1): ");
                graph_BFS(g, startVertex);
                break;
            case OPTION_DFS:
                printf("DFS Traversal(option-2): ");
                graph_DFS(g, startVertex);
                break;
            case OPTION_EXIT:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (option != OPTION_EXIT);

    Graph_destroy(g);
    return 0;
}
