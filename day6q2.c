#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int j = 0; // position for next non-zero element

    // Move non-zero elements to front
    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    // Fill remaining positions with 0
    for(int i = j; i < n; i++) {
        nums[i] = 0;
    }

    // Print result
    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}