#include <stdio.h>
#define MAX 100
#include "BSORT.h"
#include "linear_search.h"
#include "binary_search.h"

void display(int arr[],int size){
    int i=0;
    while(i<size){
        printf("%d ",arr[i++]);
    }
};

int main() {
    int n,i,choice,key,result;
    /*printf("Enter the size of the array:");
    scanf("%d",&n);*/
    int arr[]={2,3,6,5,9,4,1,7};
    n=sizeof(arr)/sizeof(int);
    /*printf("enter the array:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);*/
    printf("index:%d\n",n);
    display(arr,n);

    printf("Menu:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the key to search: ");
    scanf("%d", &key);

    switch (choice) {
        case 1:
            result = linear_search(arr, n, key);
            if (result == 1)
                printf("Element %d found at in the array.\n", key);
            else
                printf("Element %d not found in the array.\n",key);
            break;
        
        case 2:
            result = binary_search(arr, n, key);
            if (result == 1)
                printf("Element %d found at in the array.\n", key);
            else
                printf("Element %d not found in the array.\n", key);
            break;
        
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}
