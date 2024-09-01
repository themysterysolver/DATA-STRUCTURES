#include <stdio.h>
void insert(int a[], int* n, int pos, int value){
    if(pos < 0 || pos > *n){
        printf("You dare?");
        fflush(stdin);
        getchar();
        while(1)
            printf("You Shouldn't have!!");
    }
    for(int i = *n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = value;
    (*n)++;
}
void delete(int a[], int* n, int pos, int value){
    int found = 0;
    if(pos > -1 && pos < *n){
        for(int i = pos; i < *n; i++)
            a[i] = a[i + 1];
        (*n)--;
    }
    else if(pos == -1){
        for(int i = 0; i < *n; i++)
            if(!found){
                if(a[i] == value){
                    found = 1;
                    a[i] = a[i + 1];
                }
            }
            else
                a[i] = a[i + 1];
        if(found)   (*n)--;
    }
    else{
        printf("You dare?");
        fflush(stdin);
        getchar();
        while(1)
            printf("You Shouldn't have!!");
    }
}
int linearSearch(int a[], int n, int key){
    printf("%d\n", n);
    for(int i = 0; i < n; i++)
        if(i == key)
            return 1;
    return 0;
}
int binarySearch(int a[], int n, int key){
    printf("\n");
    for(int j = 0; j < n; j++)
        printf("%d ", a[j]);
    if(n == 1)
        if(*a == key)
            return 1;
        else
            return 0;
    int mid = n / 2;
    if(a[mid] > key)
        binarySearch(a, mid, key);
    else if(a[mid] < key)
        binarySearch(a + mid, n - mid, key);
    else return 1;
}
int bubbleSort(int a[], int n){
    for(int i = 0; i < n; i++)
        for(int j = 1; j < n - i; j++)
            if(a[j - 1] > a[j]){
                a[j - 1] = a[j] + a[j - 1];
                a[j] = a[j - 1] - a[j];
                a[j - 1] = a[j - 1] - a[j];
            }
    return 0;
}
int main(){
    int arr[256], input = 0, n = 0, ch1 = 0, ch2 = 0, in;
    while(1){
        printf("Enter 1 for insert\nEnter 2 for delete\nEnter 3 for search\nEnter 4 for sort\nEnter 5 for display\nEnter anything else to exit\n");
        printf("Enter your choice :");
        scanf("%d",&ch1);
        switch(ch1){
            case 1:
                if(n == 256){
                    printf("Stack Overflow! Delete atleast one element before entering more!\n");
                    break;
                }
                printf("Enter a number to insert:");
                scanf("%d", &input);
                printf("Enter position to be inserted at\n(Remember, only %d elements have been inserted so far. Exceed at your own risk):", n);
                scanf("%d", &ch2);
                insert(arr, &n, ch2, input);
                break;
            case 2:
                printf("Enter 1 to delete by index\n Enter 2 to delete by value:");
                scanf("%d", &ch2);
                if(ch2 == 1){
                    printf("Enter position to be deleted\n(Remember, only %d elements have been inserted so far. Exceed at your own risk):", n);
                    scanf("%d", &input);
                    delete(arr, &n, input, 0);
                }
                else {
                    printf("Enter value to be deleted\n(Only first instace will be deleted):");
                    scanf("%d", &input);
                    delete(arr, &n, -1, input);
                }
                break;
            case 3:
                printf("Enter 1 for linear search\n Enter 2 for binary search:");
                scanf("%d", &ch2);
                printf("Enter value to be searched for:");
                scanf("%d", &input);
                if(ch2 == 1)
                    in = linearSearch(arr, n, input);
                else
                    in = binarySearch(arr, n, input);
                if(in)
                    printf("%d found in the array\n", input);
                else{
                    bubbleSort(arr, n);
                    printf("You have either not inputted %d or you have already deleted!\n", input);
                }
                break;
            case 4:
                bubbleSort(arr, n);
                printf("Sorted!\n");
                break;
            case 5:
                for(input = 0; input < n; input++)
                    printf("%d ",arr[input]);
                printf("\n");
                break;
            default:
                printf("Exiting...");
                return 0;
        }
    }
}