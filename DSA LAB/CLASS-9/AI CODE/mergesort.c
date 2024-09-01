#include <stdio.h>


void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];

    
    for (i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = low; 

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

  
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Function to print an array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver program to test the functions
int main() {
    int l,i;
	printf("enter the length of the array:"); //length
	scanf("%d",&l);
	int arr[l];
	printf("\nenter the array:\n"); //arr i/o
	for(i=0;i<l;i++){
	    scanf("%d",&arr[i]);
	}   
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    // Perform merge sort
    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return 0;
}
