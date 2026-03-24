#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Flags for first row and column
    int firstRow = 0, firstCol = 0;

    // Check first row
    for(int j = 0; j < n; j++) {
        if(matrix[0][j] == 0)
            firstRow = 1;
    }

    // Check first column
    for(int i = 0; i < m; i++) {
        if(matrix[i][0] == 0)
            firstCol = 1;
    }

    // Use first row & column as markers
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set rows to 0
    for(int i = 1; i < m; i++) {
        if(matrix[i][0] == 0) {
            for(int j = 1; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set columns to 0
    for(int j = 1; j < n; j++) {
        if(matrix[0][j] == 0) {
            for(int i = 1; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle first row
    if(firstRow) {
        for(int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // Handle first column
    if(firstCol) {
        for(int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    // Print result
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}