//TO CREATE A GRAPH AND DO BFS DFS!!
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 20
bool visited[MAX];
void BFS(int startvertex,int v,int adjmatrix[][MAX]);
void DFS(int startvertex,int v,int adjmatrix[][MAX]);
void DFSs(int startvertex,int v,int adjmatrix[][MAX]);
int main(){
    printf("ENTER THE NO OF VERTICES:");
    int v,i,j,sv;
    char ch;
    scanf("%d",&v);
    int adjmatrix[MAX][MAX];
    printf("enter matrix:\n");
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            scanf("%d",&adjmatrix[i][j]); //&
    printf("the entered matrix is:\n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++)
            printf("%d ",adjmatrix[i][j]);
        printf("\n");
    }
    printf("\na.BFS\nb.DFS\nc.DFSs\nx.exit");
    printf("\nenter choice:");
    while(1){
        printf("\n");
        scanf(" %c",&ch);
        switch(ch){
            case 'a':
                printf("\nenter the starting vertex:");
                scanf("%d",&sv);
                BFS(sv,v,adjmatrix);
                break;
            case 'b':
            printf("enter the starting vertex:");
                scanf("%d",&sv);
                printf("DFS:");
                DFS(sv,v,adjmatrix);
                break;
            case 'c':
            printf("enter the starting vertex:");
                scanf("%d",&sv);
                printf("DFS using stack:");
                DFSs(sv,v,adjmatrix);
                break;
            case 'x':
                exit(1);

        }
    }

}
void BFS(int startvertex,int v,int adjmatrix[][MAX]){
    int queue[MAX];
    int front=-1,rear=-1,i;    

    visited[startvertex]=true;                      
    queue[++rear]=startvertex;                      
    printf("BFS TRAVERSAL IS:%d",startvertex);
    
    while(front<=rear){
        int cv=queue[++front];                 
        for(i=0;i<v;i++){
            if(adjmatrix[cv][i]==1 && !visited[i]){  
                visited[i]=true;
                queue[++rear]=i;
                printf(" %d",i);
            }
        }
    }
}
void DFS(int startvertex,int v,int adjmatrix[][MAX]){
    visited[startvertex]=true;
    printf(" %d",startvertex);
    for(int i=0;i<v;i++)
        if(adjmatrix[startvertex][i]==1 && !visited[i])
        {
            visited[i]=true;
           // printf(" %d",i);
            DFS(i,v,adjmatrix);
        }
}

void DFSs(int startvertex,int v,int adjmatrix[][MAX]){
    int stack[MAX];
    int top=-1;
    stack[++top]=startvertex;
    visited[startvertex]=true;
    printf("%d ",startvertex);
    while(top!=-1)
    {
        int cv=stack[top];
        for(int i=0;i<v;i++)
            if(adjmatrix[cv][i]==1 && !visited[i])
                {
                    visited[i]=true;
                    stack[++top]=i;
                    printf("%d ",i);
                    break;
                }
    }
}
/*
0 0 1 0 0 0
0 0 1 1 0 0
1 1 0 0 1 0
0 1 0 0 1 1
0 0 1 1 0 0
0 0 0 1 0 0
*/
