#include <stdio.h>

void display(int a[], int n)
{
    int i = 0;
	printf("Your array:\n");
	for (i = 0; i < n; i++)
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

void mergeinto(int a[], int x[], int n1, int y[], int n2)
{
    int i = 0, j = 0;
	while (1)
	{
		if (i < n1 && j <n2)
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
		else if (i == n1 && j <n2)
		{
			a[i + j] = y[j++];
		}
		else if (i < n1)
		{
			a[j + i] = x[i++];
		}
		else
			break;
	}
}


int main()
{
	int arr1[256], arr2[256], arr[512], n1, n2, i;
        printf("Enter number of elements of arr 1:");
        scanf("%d", &n1);
        printf("Enter number of elements of arr 2:");
        scanf("%d", &n2);
        printf("Ener your data of arr 1\n");
        for (i = 0; i < n1; i++)
        {
                printf("Enter %d:", i);
                scanf("%d", arr1 + i);
        }
        printf("Ener your data of arr 2\n");
        for (i = 0; i < n2; i++)
        {
                printf("Enter %d:", i);
                scanf("%d", arr2 + i);
        }
		bubb(arr1, 0, n1);
		bubb(arr2, 0, n2);
        display(arr1, n1);
        display(arr2, n2);
        mergeinto(arr, arr1, n1, arr2, n2);
        display(arr, n1 + n2);
        return 0;
}