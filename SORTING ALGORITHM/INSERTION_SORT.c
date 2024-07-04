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
    int arr[]={3,1,2,12,11,8,7,9,6,4,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("\nthe array before sorting is:");
    display(arr,size);
    ins(arr,size);
    printf("\nthe array after sorting is:");
    display(arr,size);
}