#include <stdio.h>
void multiply(int A[10][10], int B[10][10], int C[10][10], int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transpose(int M[10][10], int result[10][10], int rows, int cols) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[j][i] = M[i][j];
}

int main() {
    int A[10][10], B[10][10], C[10][10], T[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for matrix A: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter rows and columns for matrix B: ");
    scanf("%d%d", &r2, &c2);

    if(c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        return 0;
    }

    printf("Enter elements of matrix A:\n");
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for(int i = 0; i < r2; i++)
        for(int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    multiply(A, B, C, r1, c1, c2);
    transpose(C, T, r1, c2);

    printf("Resultant matrix after multiplication:\n");
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    printf("Transpose of the resultant matrix:\n");
    for(int i = 0; i < c2; i++) {
        for(int j = 0; j < r1; j++)
            printf("%d ", T[i][j]);
        printf("\n");
    }

    return 0;
}
