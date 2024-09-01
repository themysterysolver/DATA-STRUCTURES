//BUBBLE SORT in a array using FUNCTIONS!!
#include <stdio.h>
void bubble_sort(int arr[],int n); //FUNCTION DECLARATION!!
int main()
{
    int i,n1,arr1[20];
    printf("enter the no elements for array-1:");
    scanf("%d",&n1);

    printf("enter the array of elements for array-1:\n");
    for(i=0;i<n1;i++)
        scanf("%d",&arr1[i]);
    bubble_sort(arr1,n1); //FUNCTION CALL!!
    printf("\narray1 elements in sorted order:");
    for(i=0;i<n1;i++)
        printf(" %d",arr1[i]);
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
