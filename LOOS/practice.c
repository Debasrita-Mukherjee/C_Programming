// #include <stdio.h>
// #include <limits.h>
// #define N 6
// int m[7][7];
// int s[7][7];
// void printOptimalParenthesis(int i, int j)
// {
//  if (i == j)
//  {
//  printf("A%d", i);
//  return;
//  }
//  printf("(");
//  printOptimalParenthesis(i, s[i][j]);
//  printOptimalParenthesis(s[i][j] + 1, j);
//  printf(")");
// }
// int main()
// {
//  int p[] = {30, 35, 15, 5, 10, 20, 25};
//  for (int i = 1; i <= N; i++)
//  m[i][i] = 0;
//  for (int L = 2; L <= N; L++)
//  {
//  for (int i = 1; i <= N - L + 1; i++)
//  {
//  int j = i + L - 1;
//  m[i][j] = INT_MAX;
//  for (int k = i; k < j; k++)
//  {
//  int q = m[i][k] + m[k + 1][j] +
//  p[i - 1] * p[k] * p[j];
//  if (q < m[i][j])
//  {
//  m[i][j] = q;
//  s[i][j] = k;
//  }
//  }
//  }
//  }
//  printf("Minimum number of multiplications = %d\n\n", m[1][N]);
//  printf("Optimal Parenthesization: ");
//  printOptimalParenthesis(1, N);
//  printf("\n\n");
//  printf("Cost Table (m):\n");
//  for (int i = 1; i <= N; i++)
//  {
//  for (int j = 1; j <= N; j++)
//  {
//  if (j < i)
//  printf(" - ");
//  else
//  printf("%6d ", m[i][j]);
//  }
//  printf("\n");
//  }
//  printf("\nSplit Table (s):\n");
//  for (int i = 1; i <= N; i++)
//  {
//  for (int j = 1; j <= N; j++)
//  {
//  if (j <= i)
//  printf(" - ");
//  else
//  printf("%4d ", s[i][j]);
//  }
//  printf("\n");
//  }
//  return 0;
// }
#include <stdio.h>
#define MAX 100
int recursiveBinarySearch(int arr[], int low, int high, int key)
{
if(low > high)
return -1;
int mid = (low + high) / 2;
if(arr[mid] == key)
return mid;
else if(key < arr[mid])
return recursiveBinarySearch(arr, low, mid - 1, key);
else
return recursiveBinarySearch(arr, mid + 1, high, key);
}
int nonRecursiveBinarySearch(int arr[], int n, int key)
{
int low = 0, high = n - 1;
while(low <= high)
{
int mid = (low + high) / 2;
if(arr[mid] == key)
return mid;
else if(key < arr[mid])
high = mid - 1;
else
low = mid + 1;
}
return -1;
}
int main()
{
int n, key, i, choice, result;
printf("Enter number of elements: ");
scanf("%d", &n);
int arr[MAX];
printf("Enter sorted elements:\n");
for(i = 0; i < n; i++)
scanf("%d", &arr[i]);
printf("Enter element to search: ");
scanf("%d", &key);
printf("\n1. Recursive Binary Search\n");
printf("2. Non-Recursive Binary Search\n");
printf("Enter your choice: ");
scanf("%d", &choice);
if(choice == 1)
result = recursiveBinarySearch(arr, 0, n - 1, key);
else
result = nonRecursiveBinarySearch(arr, n, key);
if(result != -1)
printf("Element found at position %d\n", result + 1);
else
printf("Element not found.\n");
return 0;
}