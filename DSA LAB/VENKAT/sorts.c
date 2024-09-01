#include <stdio.h>

void display(int a[], int n)
{
	printf("Your array:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void bubb(int a[], int i, int n)
{
	printf("Pass %d %d\n", i, n);
	display(a, n);
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

void merge(int a[], int mid, int n)
{
	printf("In merge with %d %d\n", mid, n);
	display(a, n);
	int x[256], y[256];
	for (int i = 0; i < mid; i++)
	{
		printf("vvvvvv\n\n\n\n\n");
		x[i] = a[i];
	}
	for (int i = 0; i < n - mid; i++)
	{
		printf("%d %dc", a[mid + i], a[i]);
		printf("\n\n\n\n\n\n");
		y[i] = a[mid + i];
	}
	int i = 0, j = 0;
	printf("Xs and Ys\n");
	display(x, mid);
	display(y, n - mid);
	while (1)
	{
		if (i < mid && j < n - mid)
		{
			if (x[i] < y[j])
			{
				a[i + j] = x[i++];
			}
			else
			{
				a[i + j] = y[j++];
			}
		}
		else if (i == mid && j < n - mid)
		{
			a[i + j] = y[j++];
		}
		else if (i < mid)
		{
			a[j + i] = x[i++];
		}
		else
			break;
	}
	printf("In merge with %d %d\n", mid, n);
	display(a, n);
}

void mergeSort(int a[], int n)
{
	printf("%d\n", n);
	display(a, n);
	int mid = n / 2;
	if (mid == 0)
		return;
	mergeSort(a, mid);
	mergeSort(a + mid, n - mid);
	merge(a, mid, n);
}

int main()
{
	int arr[256], n, ch;
        printf("Enter number of elements:");
        scanf("%d", &n);
        printf("Ener your data\n");
        for (int i = 0; i < n; i++)
        {
                printf("Enter %d:", i);
                scanf("%d", arr + i);
        }
        display(arr, n);
        mergeSort(arr, n);
        display(arr, n);
        return 0;
}