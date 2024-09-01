#include <stdio.h>
int main(){
    int i,j,n;
    printf("enter the no elements for array-1:");
    scanf("%d",&n);

    printf("enter the array of elements for array-1:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr1[i]);
    int temp[n]={0};
    for(i=0;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if((arr[i]==arr[j]) && i!=j){
                printf("%d is not unique\n",arr[i]);
            }
            else
                printf("%d is unique\n");
        }    }
}
