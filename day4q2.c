#include <stdio.h>

int removeElement(int nums[], int n, int val) {
    int k = 0; // count of elements not equal to val

    for (int i = 0; i < n; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int n, val;

    // Input size
    scanf("%d", &n);

    int nums[100];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Input value to remove
    scanf("%d", &val);

    int k = removeElement(nums, n, val);

    // Print first k elements
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}