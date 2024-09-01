//PRIM'S ALGORITHM!!
#include<stdio.h>
#include<stdbool.h>
#define MAX 10
#define infinity 99999
int main(){
    printf("ENTER THE NO OF VERTICES:");
    int v,i,j,w,ch,sv;
    scanf("%d",&v);
    int g[v][v];
    printf("enter the start vertex---end vertex---weight:\n");
    while(1){
        scanf("%d %d %d",&i,&j,&w); //i start and j dest!!
        if(i>v || j>v){
            printf("enter valid source and destination!!");
            continue;
        }
        g[i][j]=w;
        g[j][i]=w;
        printf("enter 0 to break the loop enter 1 to continue:");
        scanf("%d",&ch);
        if(!ch)
            break;
    }
    bool visited[v]; //visited array to find the visited vertices!!
    printf("enter the startvertex:");
    scanf("%d",&sv);
    visited[sv]=true;   //PRIM'S ALGORITHM!!
    int edge=0;
    int x=0,y=0,min,cost;
    printf("MINIMU SPANNING TREE!!\n");
    printf("FROM->TO----WEIGHT!!\n");
    while(edge<v-1){            //coz,in MST nE<nV-1
        x=0;
        y=0;
        min=infinity;
        for(i=0;i<v;i++){
            if(visited[i]){ //only if VISITED ENTERS AND CHECKS!!
                for(j=0;j<v;j++){
                        if(!visited[j]&&g[i][j])    //NOT VISITED NA ENTERS!! &&g[i][j] is important coz 
                        {                           //it tells whether they have weight or connection between them or not!!
                            if(min>g[i][j]){        //CJECK selected g[i][j] is lesser than min!
                                min=g[i][j];
                                x=i;
                                y=j;
                            }
                        }
                }
            }
        }

    visited[y]=true;
    printf("%d->%d----%d\n",x,y,g[x][y]);
    cost+=g[x][y];
    edge++;
    }
    printf("TOTAL MINIMUM COST OF MST:%d",cost);

}
