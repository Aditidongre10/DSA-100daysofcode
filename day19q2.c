#include <stdio.h>

// Kadane for max subarray
int kadaneMax(int arr[], int n) {
    int maxSum = arr[0], curr = arr[0];

    for(int i = 1; i < n; i++) {
        if(curr + arr[i] > arr[i])
            curr = curr + arr[i];
        else
            curr = arr[i];

        if(curr > maxSum)
            maxSum = curr;
    }

    return maxSum;
}

// Kadane for min subarray
int kadaneMin(int arr[], int n) {
    int minSum = arr[0], curr = arr[0];

    for(int i = 1; i < n; i++) {
        if(curr + arr[i] < arr[i])
            curr = curr + arr[i];
        else
            curr = arr[i];

        if(curr < minSum)
            minSum = curr;
    }

    return minSum;
}

int maxCircularSum(int arr[], int n) {
    int total = 0;

    for(int i = 0; i < n; i++) {
        total += arr[i];
    }

    int max_normal = kadaneMax(arr, n);
    int min_sub = kadaneMin(arr, n);

    // If all elements are negative
    if(max_normal < 0)
        return max_normal;

    int max_circular = total - min_sub;

    return (max_normal > max_circular) ? max_normal : max_circular;
}

int main() {
    int nums[] = {5, -3, 5};
    int n = 3;

    printf("Maximum Circular Subarray Sum: %d", maxCircularSum(nums, n));

    return 0;
}