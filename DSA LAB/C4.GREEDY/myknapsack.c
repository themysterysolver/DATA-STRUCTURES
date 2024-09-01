#include<stdio.h>
#define MAX 20
int main(){
    int n,i,j,weight[MAX],profit[MAX],capacity=0; //capacity is the space left!
    float temp,ratio[MAX],total=0;
    printf("enter the no of objects:"); //GET n-obj size
    scanf("%d",&n);
    for(i=0;i<n;i++){                   //GET weight and profit!!
        printf("\nenter the profit and weight for '%d object': ",i+1);
        scanf("%d %d",&profit[i],&weight[i]);
    }
    printf("enter the total capacity:");    //get M or capacity!!
    scanf("%d",&capacity);

    for(i=0;i<n;i++)                        //calculated the profit to weight ratio!!!
        ratio[i]=((float)profit[i])/(weight[i]);

    for(i=0;i<n;i++)                        //BUBBLE SORT FOR Lowest value to the RIGHT MOST!!
        for(j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;

                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;

                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
            }
    }
    printf("\nthe solution for the given knapsack problem:\n");
    for(i=0;i<n;i++){
        if(weight[i]>capacity){
            total=total+((ratio[i]*capacity));
            break;
        }
        else{
            total=total+profit[i];
            capacity=capacity-weight[i];
            printf("TOTAL VALUE[%d]:%f\n",i,total);
        }
    }
    printf("TOTAL VALUE:%f",total);

}
