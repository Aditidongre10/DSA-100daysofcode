#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;        // last element in nums1
    int j = n - 1;        // last element in nums2
    int k = m + n - 1;    // last position in nums1

    // Merge from end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements from nums2
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int nums1[100], nums2[100];
    int m, n;

    // Input m
    scanf("%d", &m);

    // Input first m elements of nums1
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    // Input n
    scanf("%d", &n);

    // Input nums2
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // Call merge
    merge(nums1, m, nums2, n);

    // Print merged array
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}