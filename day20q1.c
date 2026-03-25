#include <stdio.h>
#include <stdlib.h>

// Simple hash map using array (for small range)
#define SIZE 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    // Hash map (frequency of prefix sums)
    int freq[SIZE] = {0};

    // To handle prefix sum = 0
    freq[0] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If this sum seen before
        if(prefixSum >= 0 && prefixSum < SIZE) {
            count += freq[prefixSum];
            freq[prefixSum]++;
        }
    }

    printf("%d", count);

    return 0;
}