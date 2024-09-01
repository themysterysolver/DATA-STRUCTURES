#include <stdio.h>

void display(int a[], int n)
{
    int i;
	printf("Your array:\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int linearSearch(int a[], int n, int key)
{
    display(a, n);
    printf("%d c\n", key);
    int i;
	printf("%d\n", n);
	for (i = 0; i < n; i++)
		if (a[i] == key)
			return 1;
	return 0;
}
void checkunique(int a[], int n){
    int i = 0;
    for(i = 0; i < n; i++){
        if(linearSearch(a, i, a[i]) || linearSearch(a + i + 1, n - i - 1, a[i])){
            printf("Your array contains duplicate!");
            return ;
        }
    }
    printf("Your array is unique");
}

int main(){
    int arr[256], n, ch = 0, i;
        printf("Enter number of elements:");
        scanf("%d", &n);
        printf("Ener your data\n");
        for (i = 0; i < n; i++)
        {
                printf("Enter %d:", i);
                scanf("%d", arr + i);
        }
        checkunique(arr, n);
        return 0;
}