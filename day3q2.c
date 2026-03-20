#include <stdio.h>

int main() {
    int n;

    // Input n
    scanf("%d", &n);

    int arr[100];

    // Input n-1 elements
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    // Expected sum of 1 to n
    int total = n * (n + 1) / 2;

    // Actual sum of array
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    // Missing number
    int missing = total - sum;

    printf("%d", missing);

    return 0;
}