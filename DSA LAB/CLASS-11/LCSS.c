#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longest_increasing_subsequence(int arr[], int n) {
    int lis[n];
    int max_lis = 1;

    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
        max_lis = max(max_lis, lis[i]);
    }

    return max_lis;
}

int main() {
    int n;
    printf("Enter the number of elements in the sequence: ");
    scanf("%d", &n);

    int sequence[n];
    printf("Enter the sequence of numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    int result = longest_increasing_subsequence(sequence, n);
    printf("Length of the longest increasing subsequence: %d\n", result);

    return 0;
}

