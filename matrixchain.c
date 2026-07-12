#include <stdio.h>
#include <limits.h>

// Function to find the minimum cost of matrix chain multiplication
int matrixChainOrder(int p[], int n) {
    // m[i][j] will store the minimum number of scalar multiplications
    // needed to compute the matrix product A[i]...A[j]
    int m[n][n];

    // Cost is 0 when multiplying one matrix
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX; // Initialize to infinity

            // Try all possible splits between i and j
            for (int k = i; k <= j - 1; k++) {
                // q = cost of left split + cost of right split + cost of multiplying the two results
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    // The answer for the full chain (1 to n-1) is stored here
    return m[1][n - 1];
}

int main() {
    // Array p[] represents the dimensions of the matrices
    // Matrix i has dimensions p[i-1] x p[i]
    // Here we have 4 matrices:
    // A1: 10x20, A2: 20x30, A3: 30x40, A4: 40x30
    int p[] = {10, 20, 30, 40, 30};
    int size = sizeof(p) / sizeof(p[0]);

    printf("Minimum number of multiplications is: %d\n", matrixChainOrder(p, size));

    return 0;
}