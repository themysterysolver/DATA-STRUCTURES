//bubble sort!!
#include<stdio.h>
void bs(int arr[],int l);
void display(int arr[],int size);
int main(){
    int n,i;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("size of array is:%d",size);
    printf("\nthe array before sorting is:");
    display(arr,size);
    bs(arr,size);
    printf("\nthe array after sorting is:");
    display(arr,size);
}
void bs(int arr[],int l){
    int i=0,j=0;
    for(i=0;i<l;i++){   //runs n-times
        for(j=0;j<l-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            // printf("\n");
            // display(arr,l);
        }
    }
}
void display(int arr[],int size){
    int i=0;
    while(i<size){
        printf("%d ",arr[i++]);
    }
}
