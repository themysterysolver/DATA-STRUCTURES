#include <stdio.h>
int main(){
    int i,j,n,tit=0;
    int arr[100];
    printf("enter the no elements for array:");
    scanf("%d",&n);
    printf("enter the array of elements for array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    int flag=1;
    int temp[n];
    temp[0]=arr[0];
    for(i=0;i<=n;i++){
        for(j=0;j<i;j++)
            if(arr[i]==arr[j])
                flag=0;
        if(flag==1)
        {    
            for(j=i+1;j<=n;j++){
                if((arr[i]==arr[j]) && i!=j){
                    printf("%d is a duplicate in %d position!\n",arr[i],j); 
                    tit=1;
                }

        }  
        }   
    }
    if(tit==0)
            printf("there are no duplicates!");
}
