#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int matrixChainOrder(int p[], int n) {
    // Dynamically allocate the 2D array for the DP table
    int **m = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        m[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }


    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX; 

            
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    int result = m[1][n - 1];

    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);

    return result;
}

int main() {
    int num_matrices;

    printf("Enter the number of matrices: ");
    if (scanf("%d", &num_matrices) != 1 || num_matrices < 1) {
        printf("Invalid number of matrices.\n");
        return 1;
    }

    // For 'count' matrices, we need 'count + 1' elements in the dimensions array
    int n = num_matrices + 1;
    int *p = (int *)malloc(n * sizeof(int));

    printf("\n--- Dimension Input ---\n");
    printf("Matrix i has dimensions: row [i-1] x col [i]\n");
    
    // Get row dimension for the first matrix
    printf("Enter row size for Matrix 1: ");
    scanf("%d", &p[0]);

    // Get column dimensions for all matrices
    for (int i = 1; i < n; i++) {
        printf("Enter column size for Matrix %d: ", i);
        scanf("%d", &p[i]);
    }

    // Print out what the user entered to verify
    printf("\nYour Matrix Chain Dimensions:\n");
    for (int i = 1; i < n; i++) {
        printf("Matrix %d: %d x %d\n", i, p[i-1], p[i]);
    }

    int min_ops = matrixChainOrder(p, n);
    printf("\nMinimum number of multiplications needed: %d\n", min_ops);

    free(p);
    return 0;
}