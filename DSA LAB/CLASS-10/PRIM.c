#include<stdio.h>

int inf = 9999 ; // infinity value!!!
int i = 0 , j = 0 ;

void main(){

        int v , stop = 0 , src , dest , wght , sel , min , x , y , edge = 0 , mincost = 0 ;
        printf("Enter the total no of vertex : ");
        scanf("%d",&v); //total  no of vertex-v!
        int g[v][v] ;
        do{
        printf("Enter source - destination - weight : ");
        scanf("%d %d %d",&src,&dest,&wght);
        g[src][dest] = wght ;
        g[dest][src] = wght ;  //undirected graph!!
        printf("Enter 0 to continue :");
        scanf("%d",&stop);
        }while(!stop);

        int selected[v] ; //visited vertex!!
        for(i = 0 ; i < v ; i++)selected[i] = 0 ; //initialising them to zero!!!
        i= 0 ;
        printf("Start from vertex :");//startvertex!!
        scanf("%d",&sel);
        selected[sel] = 1 ; //startvertex=1!
        printf("edge     weight\n");
        while( edge < v-1){          //MAIN PRIM'S ALGORITHM!!!!!!! ------------------- wkt,n(E(mst))<n(v)-1
        min = inf ;                  //setting min to (max value) each time!!!!
        x = 0 , y = 0 ;              //x denotes ROWS,y denotes COLUMN!!
        for( i = 0 ; i < v ; i++ ){
            if(selected[i]){
                for(j = 0 ; j < v ; j++){
                        if( !selected[j] && g[i][j]){
                                if( min > g[i][j]){
                                                min = g[i][j];
                                                x = i ; y = j ; //x-start,y-end!!
                                        }
                        }

                }
                }
        }
        printf("%d -> %d => %d\n",x,y,g[x][y]);
        selected[y] = 1; //making the chossen end vertex to selected
        mincost += g[x][y] ; //cost of MST!!!!
        edge++ ; //incrementing edge!

        }
        printf("=============\nTotal Minimum cost : %d\n=============\n",mincost);
}