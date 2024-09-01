//bubble sort!-using recursion!!!
//bubble sort!!
#include<stdio.h>
void bs(int arr[],int l);
void display(int arr[],int size);
int main(){
    int arr[]={1,3,9,2,6,10,22,11};
    /*int n,i;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);*/
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
    // Base case: If only one element remains, array is sorted
    if (l == 1) {
        return;
    }
    for(i=0;i<l;i++){   //runs n-times
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
            bs(arr,l-1);
            // printf("\n");
            // display(arr,l);
        }
}

void display(int arr[],int size){
    int i=0;
    while(i<size){
        printf("%d ",arr[i++]);
    }
}
