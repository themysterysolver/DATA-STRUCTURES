//INSERTION SORT!!
#include<stdio.h>
void display(int arr[],int size){
    int i=0;
    while(i<size){
        printf("%d ",arr[i++]);
    }
}
void ins(int arr[],int n){
    int i,j;
    for(i=1;i<n;i++){ //n passes!!
        int x=arr[i];
        int j=i-1;
        while(arr[j]>x && j>-1){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}
int main(){
    int n,i;
    printf("Enter the ssize of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]); 
    int size=n;
    printf("the array before sorting is:");
    display(arr,size);
    ins(arr,size);
    printf("\nthe array after sorting is:");
    display(arr,size);
}