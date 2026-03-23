#include <stdio.h>

// Function to reverse array in-place
void reverse(char s[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        // swap
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char s[n];

    // Input characters
    for (int i = 0; i < n; i++) {
        scanf(" %c", &s[i]);
    }

    reverse(s, n);

    // Print reversed array
    for (int i = 0; i < n; i++) {
        printf("%c ", s[i]);
    }

    return 0;
}