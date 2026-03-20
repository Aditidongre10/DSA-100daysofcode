#include <stdio.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[100];

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0;
    int right = n - 1;
    int temp;

    // Reverse using two pointers
    while (left < right) {
        // Swap
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move pointers
        left++;
        right--;
    }

    // Print reversed array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}