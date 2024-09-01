#include <stdio.h>


int partition(int arr[], int low, int high) { 
    int pivot = arr[high];  
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++) {
        
        if (arr[j] <= pivot) {
            i++; 
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);  
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partition point
        int pi = partition(arr, low, high);

        // Recursive calls to sort the two halves
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, arr_size - 1);// Perform quick sort

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return 0;
}
