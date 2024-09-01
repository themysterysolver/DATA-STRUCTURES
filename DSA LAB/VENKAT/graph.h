#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct
{
	int n;
	int **adjMatrix;
} adjMatrix;

typedef struct
{
	int n;
	linklist **adjList;
} adjList;

adjMatrix createAdjMatrix(int n)
{
	int **A = (int **)malloc(n * sizeof(int *));
	int i;
	for (i = 0; i < n; i++)
		A[i] = (int *)malloc(n * sizeof(int));
	adjMatrix m = {n, A};
	return m;
}

adjList createAdjList(int n)
{
	adjList a = {n, (linklist **)calloc(n, sizeof(linklist *))};
	return a;
}

adjMatrix createAdjMatrixFromAdjList(adjList l)
{
	adjMatrix m = createAdjMatrix(l.n);
	linklist *traverser = NULL;
	int i = 0;
	for (i = 0; i < l.n; i++)
	{
		traverser = l.adjList[i];
		while (traverser)
		{
			m.adjMatrix[i][traverser->value] = 1;
			traverser = traverser->next;
		}
	}
}

adjList createAdjListFromAdjMatrix(adjMatrix m)
{
	adjList l = createAdjList(m.n);
	int i, j;
	for (i = 0; i < m.n; i++)
		for (j = 0; j < m.n; j++)
			if (m.adjMatrix[i][j])
				insert(&l.adjList[i], j, -1);
	return l;
}

void bfs(adjList g)
{
	int i = 0;
	printf("%d ", i);
	queue q = {NULL};
	linklist *temp = g.adjList[i], *visited = NULL;
	insert(&visited, 0, 0);
	do
	{
		while (temp)
		{
			if (!in(visited, temp->value))
			{
				insert(&visited, temp->value, 0);
				enqueue(&q, temp->value);
				printf("%d ", temp->value);
			}
			temp = temp->next;
		}
		temp = g.adjList[dequeue(&q)];
	} while (!qIsEmpty(q));
}

adjMatrix randomAdjMatrix(int n)
{
	int i, j;
	adjMatrix m = createAdjMatrix(n);
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
			m.adjMatrix[i][j] = m.adjMatrix[j][i] = rand() % 2;
		m.adjMatrix[i][i] = 0;
	}
	return m;
}

void printAdjMAtrix(adjMatrix m)
{
	int i, j;
	for (i = 0; i < m.n; i++)
	{
		for (j = 0; j < m.n; j++)
			printf("%d ", m.adjMatrix[i][j]);
		printf("\n");
	}
}

void printAdjList(adjList a)
{
	int i;
	for (i = 0; i < a.n; i++)
	{
		printf("%d -> ", i);
		print(a.adjList[i]);
	}
}
