#include <stdio.h>

int main() {
    int n1, n2;

    // Input sizes
    scanf("%d", &n1);
    int nums1[n1];

    for(int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }

    scanf("%d", &n2);
    int nums2[n2];

    for(int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }

    int result[n1]; // max possible size
    int k = 0;

    // Find intersection
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(nums1[i] == nums2[j]) {
                result[k++] = nums1[i];
                nums2[j] = -1; // mark as used
                break;
            }
        }
    }

    // Print result
    for(int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}