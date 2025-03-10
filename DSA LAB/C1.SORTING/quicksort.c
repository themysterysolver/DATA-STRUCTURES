//quick sort!!
#include<stdio.h>
void quicksort(int l,int h,int arr[]); 
int partion(int l,int h,int arr[]);
void swap(int a,int b,int arr[]);
int main(){
    int n,i=0,max=999999;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int ln=n+1;
    int arr[ln];
    printf("enter the array:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    arr[n]=max;
    printf("\nthe array before sorting is:");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    quicksort(0,n,arr);
    printf("\nthe array after sorting is:");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
int partion(int l,int h,int arr[]){
    int i=l;
    int j=h;
    int pivot=arr[l];
    while(i<j){ //when j>i it should break!!
        do{
            i++;
            if(i>j)
                break;
        }while(arr[i]<=pivot); //when arr>pivot it should break!
        do{
            j--;
            if(i>j)
                break;
        }while(arr[j]>pivot);
        if (i < j) {
            swap(i, j, arr);
        }
    }
    swap(l,j,arr);
    return j;
}
void quicksort(int l,int h,int arr[]){
    int i=l;
    int j=h;
    int k;
    if(i<j){
        k=partion(l,h,arr);
        quicksort(l,k,arr);
        quicksort(k+1,h,arr);
    }
}
void swap(int a,int b,int arr[]){
    int temp;
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}