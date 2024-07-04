//MERGE SORT!! O(NlogN)
#include <stdio.h>
#define max 100
void merge(int arr[],int l,int h,int mid);
void mergesort(int arr[],int l,int h);
void display(int arr[],int size);


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
    mergesort(arr,0,size-1);
    printf("\nthe array after sorting is:");
    display(arr,size);
}

void merge(int arr[],int l,int h,int mid){
    int n1,n2;
    n1=mid-l+1;
    n2=h-mid;
    int L1[n1];
    int L2[n2];
    int i,j,k;
    for(i=0;i<n1;i++)
        L1[i]=arr[l+i];
    for (j = 0; j < n2; j++)
        L2[j] = arr[(mid + 1) + j];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L1[i]<=L2[j]){
            arr[k]=L1[i];
            i++;
            k++;
        }
        else if(L2[j]<L1[i]){
            arr[k]=L2[j];
            j++;
            k++;
        }
    }
    while (i < n1) {
        arr[k] = L1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = L2[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,h,mid);
    }
}
void display(int arr[],int size){
    int i=0;
    while(i!=size){
        printf("%d ",arr[i++]);
    }
}
