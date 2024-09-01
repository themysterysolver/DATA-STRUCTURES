#include<stdio.h>
#include<stdbool.h>
#define MAX 20

bool visited[MAX];
void DFS(int startvertex, int v, int adjmatrix[][MAX]);

int main() {
    printf("ENTER THE NO OF VERTICES:");
    int v, i, j;
    scanf("%d", &v);
    int adjmatrix[v][v];

    printf("enter the adjacency matrix:\n");
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            scanf("%d", &adjmatrix[i][j]);

    printf("the entered matrix is:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++)
            printf("%d ", adjmatrix[i][j]);
        printf("\n");
    }

    printf("Starting Vertex for DFS:");
    int sv;
    scanf("%d", &sv);

    printf("DFS Traversal starting from vertex %d is:", sv);
    DFS(sv, v, adjmatrix);

    return 0;
}

void DFS(int startvertex, int v, int adjmatrix[][MAX]) {
    printf(" %d", startvertex);
    visited[startvertex] = true;

    for (int i = 0; i < v; i++) {
        if (adjmatrix[startvertex][i] && !visited[i]) {
            DFS(i, v, adjmatrix);
        }
    }
}
