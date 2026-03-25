#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int nums[], int n, int k) {
    k = k % n;

    // Step 1: reverse whole array
    reverse(nums, 0, n - 1);

    // Step 2: reverse first k elements
    reverse(nums, 0, k - 1);

    // Step 3: reverse remaining elements
    reverse(nums, k, n - 1);
}

int main() {
    int nums[] = {1,2,3,4,5,6,7};
    int n = 7, k = 3;

    rotate(nums, n, k);

    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}