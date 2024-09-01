# include<stdio.h>
#define INFINITY 999
int cost[10][10],distance[10],p[10],visited[10],n,i,j,source,dest,current,path[10],min;
void dijkstra();
int  main()
{   
 printf("Enter the no.of vertices:");
 scanf("%d",&n);
 printf("Enter the cost matrix:\n"); 
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   scanf("%d",&cost[i][j]);
 printf("enter the source :");
 scanf("%d",&source);
 printf("enter the destination:");
 scanf("%d",&dest); 
 dijkstra();
 return 0;
}
void dijkstra()
{
    //initialize output[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=INFINITY;
        visited[i]=0;
    }

    current = source;
    visited[current] = 1;
    distance[current] = 0;

    while(current != dest)
    {
    min=distance[current]; //check if a better path exists through current node
    for(i=0;i<n;i++)
        if(cost[current][i]!=0 && visited[i] != 1)
            if(cost[current][i]+min<distance[i])
                {
                    distance[i]=cost[current][i]+min;
                    p[i]=current;
                }   
    min=INFINITY;
    //To find node at minimum distance
    for(i=0;i<n;i++)
        if(visited[i]!=1 && distance[i]<min)
            {
            min=distance[i];
            current=i;
            }  
    visited[current]=1;
    }
    // to print Shortest path
    printf("\n Path=%d",dest);
    j=dest;
    do
        {
             j=p[j];
          printf("<-%d",j);
        }while(j!=source);
            
printf("\nShortest Distance = %d",distance[dest]);

}