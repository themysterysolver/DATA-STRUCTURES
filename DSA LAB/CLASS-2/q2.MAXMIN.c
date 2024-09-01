//INSERTION in a array with the position and elemnt of insertion is given
#include <stdio.h>
#include <conio.h>
#define MAX 50
int arr[MAX];
void bubble_sort(int arr[],int n); //FUNCTION DEFENITION!!
int main(){
    int i,j,l,arr1[20];
    printf("enter the no elements for array-1:");
    scanf("%d",&l);

    printf("enter the array of elements for array-1:\n");
    for(i=0;i<l;i++)
        scanf("%d",&arr1[i]);
    bubble_sort(arr1,l); //FUNCTION CALL!!
    printf("\narray1 elements in sorted order:");
    for(i=0;i<l;i++)
        printf(" %d",arr1[i]);
    
        int a,b;
        printf("\nenter the order of max and min to be found as 2-term space betweeen them:");
        scanf("%d %d",&a,&b);
        //printf("\nthe %d order of max num is %d\nthe  %d order of min num is %d!!\n",a,arr[a-1],b,arr[l-b]);
        if (a < 1 || a > l || b < 1 || b > l) {
        printf("Invalid positions. Please enter positions within the range (1-%d).\n", l);
        }
        else {
        printf("The %d-th maximum number is %d\n", a, arr[a - 1]);
        printf("The %d-th minimum number is %d\n", b, arr[l - b]);
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
