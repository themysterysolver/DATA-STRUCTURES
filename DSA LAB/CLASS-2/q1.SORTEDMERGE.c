//BUBBLE SORT in a array using FUNCTIONS!!
#include <stdio.h>
void bubble_sort(int arr[],int n); //FUNCTION DECLARATION!!
void merge_arr(int arr1[],int arr2[],int arr3[],int n1,int n2);
int main()
{
    int i,n1,n2,n3,temp,arr1[20],arr2[20];
    int arr3[20];
    printf("enter the no elements for array-1:");
    scanf("%d",&n1);

    printf("enter the array of elements for array-1:\n");
    for(i=0;i<n1;i++)
        scanf("%d",&arr1[i]);

    printf("enter the no elements for array-2:");
    scanf("%d",&n2);

    printf("enter the array of elements for array-2:\n");
    for(i=0;i<n2;i++)
        scanf("%d",&arr2[i]);
    n3=n1+n2;

    bubble_sort(arr1,n1); //FUNCTION CALL!!
    bubble_sort(arr2,n2); //FUNCTION CALL!!
    printf("\narray1 elements in sorted order:");
    for(i=0;i<n1;i++)
        printf(" %d",arr1[i]);
    printf("\narray2 elements in sorted order:");
    for(i=0;i<n2;i++)
        printf(" %d",arr2[i]);
    
    /*for(i=0;i<n;i++)
        printf(" %d",arr[i]);*/
    merge_arr(arr1,arr2,arr3,n1,n2);
    printf("\narray elements in sorted order:");
    for(i=0;i<n3;i++)
        printf("%d ",arr3[i]);
	return 0;
}
//  void merge_arr(int arr1[],int arr2[],int arr3[],int n1,int n2){
//      int i=0,j=0,k=0;
//      int n3=n1+n2;
//      while(k!=n3){
//          if(i==n1){
//              arr3[k]=arr2[j];
//              k++;
//              j++;
//          }
//          else if(j==n2){
//              arr3[k]=arr1[i];
//              k++;
//              i++;
//          }
            
//          else if(arr1[i]>=arr2[j]){
//              arr3[k]=arr2[j];
//              k++;
//              j++;
//              }
//          else {
//              arr3[k]=arr1[i];
//              k++;
//              i++;
//          }
        
//      }
//  }
void merge_arr(int arr1[], int arr2[], int arr3[], int n1, int n2) {
    int i = 0, j = 0, k = 0;
    int n3 = n1 + n2;
    while (k != n3) {
        if (i == n1) {
            arr3[k] = arr2[j];
            k++;
            j++;
        } else if (j == n2) {
            arr3[k] = arr1[i];
            k++;
            i++;
        } else if (arr1[i] <= arr2[j]) {
            arr3[k] = arr1[i];
            k++;
            i++;
        } else {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
}

void bubble_sort(int arr[],int n) //FUNCTION DEFENITION!!
{
    int i,temp,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
