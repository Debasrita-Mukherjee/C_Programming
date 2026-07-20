#include <stdio.h>
#include <limits.h>
#define N 6
int m[7][7];
int s[7][7];
void printOptimalParenthesis(int i, int j)
{
 if (i == j)
 {
 printf("A%d", i);
 return;
 }
 printf("(");
 printOptimalParenthesis(i, s[i][j]);
 printOptimalParenthesis(s[i][j] + 1, j);
 printf(")");
}
int main()
{
 int p[] = {30, 35, 15, 5, 10, 20, 25};
 for (int i = 1; i <= N; i++)
 m[i][i] = 0;
 for (int L = 2; L <= N; L++)
 {
 for (int i = 1; i <= N - L + 1; i++)
 {
 int j = i + L - 1;
 m[i][j] = INT_MAX;
 for (int k = i; k < j; k++)
 {
 int q = m[i][k] + m[k + 1][j] +
 p[i - 1] * p[k] * p[j];
 if (q < m[i][j])
 {
 m[i][j] = q;
 s[i][j] = k;
 }
 }
 }
 }
 printf("Minimum number of multiplications = %d\n\n", m[1][N]);
 printf("Optimal Parenthesization: ");
 printOptimalParenthesis(1, N);
 printf("\n\n");
 printf("Cost Table (m):\n");
 for (int i = 1; i <= N; i++)
 {
 for (int j = 1; j <= N; j++)
 {
 if (j < i)
 printf(" - ");
 else
 printf("%6d ", m[i][j]);
 }
 printf("\n");
 }
 printf("\nSplit Table (s):\n");
 for (int i = 1; i <= N; i++)
 {
 for (int j = 1; j <= N; j++)
 {
 if (j <= i)
 printf(" - ");
 else
 printf("%4d ", s[i][j]);
 }
 printf("\n");
 }
 return 0;
}