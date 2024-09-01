//MERGE SORT!! O(NlogN)
//DIVIDE AND CONQUER!!
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

void merge(int arr[],int l,int h,int mid){ //2way merge!!(SORTED EMRGE!!!)--#CONQUER!!
    int n1,n2;
    n1=mid-l+1; //n1- low to mid sub array!!
    n2=h-mid;   //n2- mid to high sub array!!
    int L1[n1];
    int L2[n2];
    int i,j,k;
    for(i=0;i<n1;i++)
        L1[i]=arr[l+i];  //lowest or 0th index for starting of L1 subarray is low(l)
    for (j = 0; j < n2; j++)
        L2[j] = arr[(mid + 1) + j]; //lowest or 0th index for starting of L2 subarray is low(mid+1)
    i=0;
    j=0;
    k=l; //to chaange the actual array!!
    while(i<n1 && j<n2){            //SORTED MERGE ALGORITH here after!!!
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
    while (i < n1) { //when l2 is smaller than l1
        arr[k] = L1[i];
        i++;
        k++;
    }
    while (j < n2) { //when l1 is smaller than l2
        arr[k] = L2[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int h){ //merge splitting part!!!--#DIVIDE [({DRIVER FUNCTION})]
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
