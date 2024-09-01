#include <stdio.h>

void bubb(int a[], int i, int n)
{
	if (n == i + 1)
		return;
	else
	{
		if (a[i] > a[i + 1])
		{
			a[i] = a[i + 1] + a[i];
			a[i + 1] = a[i] - a[i + 1];
			a[i] = a[i] - a[i + 1];
		}
		bubb(a, i + 1, n);
		if (i == 0)
			bubb(a, i, n - 1);
	}
}

void display(int a[], int n)
{
    int i;
	printf("Your array:\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
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
        bubb(arr, 0, n);
        printf("Enter i:");
        scanf("%d", &ch);
        printf("the max is %d\n", arr[n - 1]);
        printf("the min is %d\n", arr[0]);
        printf("the %dth smallest element is %d\n", ch, arr[ch - 1]);
        return 0;
}