#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: sort array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;

    int minSum = 1000000000; // large value
    int x = 0, y = 0;

    while(left < right) {
        int sum = arr[left] + arr[right];

        // Update closest sum
        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            x = arr[left];
            y = arr[right];
        }

        // Move pointers
        if(sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    printf("%d %d", x, y);

    return 0;
}