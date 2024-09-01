#include "graph.h"
int main(){
	int n, input = 0, choice, i, j;
	adjList list;
	adjMatrix matrix;
	printf("Enter no. of vertices:");
	scanf("%d", &n);
	list = createAdjList(n);
	matrix = createAdjMatrix(n);
	printf("Enter 1 for adjacency matrix\nEnter 2 for adjacency list\nEnter 3 for edge list\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			i = 0, j = 0;
			printf("Enter a %dx%d binary matrix\n", n, n);
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					scanf("%d", &matrix.adjMatrix[i][j]);
			printAdjMAtrix(matrix);
			list = createAdjListFromAdjMatrix(matrix);
			break;
		case 2:
			i = 0;
			for(i = 0; i < n; i++){
				printf("Enter the neighbours of %d. Enter -1 to go to next:\n", i);
				while(1){
					scanf("%d", &input);
					if(input == -1)	break;
					insert(&list.adjList[i], input, 0);
				}
			}
			printAdjList(list);
			matrix = createAdjMatrixFromAdjList(list);
			break;
		case 3:
			break;
		default:
			return 0;
	}
	printf("Enter 1 for insert\nEnter 2 for delete\nEnter 3 for search\nEnter 4 for display\n");
	while(1){
		printf("Enter your choice:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter the edge as space separated integers:");
				scanf("%d %d", &i, &j);
				matrix.adjMatrix[i][j] = 1;
				matrix.adjMatrix[j][i] = 1;
				insert(&list.adjList[i], j, 0);
				insert(&list.adjList[j], i, 0);
				break;
			case 2:
				printf("Enter the edge as space separated integers:");
				scanf("%d %d", &i, &j);
				matrix.adjMatrix[i][j] = 0;
				matrix.adjMatrix[j][i] = 0;
				del(&list.adjList[i], j);
				del(&list.adjList[j], i);
				break;
			case 3:
				bfs(list);
			case 4:
				printAdjList(list);
				printAdjMAtrix(matrix);
				break;
			default:
				return 0;
		}
	}
}

