#include <stdio.h>
#include <stdlib.h>

int x[20], count = 0;

// Function to check whether queen can be placed
int place(int k, int i)
{
    int j;
    for (j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

// Function to find all solutions
void nQueens(int k, int n)
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;

            if (k == n)
            {
                count++;
                printf("\nSolution %d:\n", count);

                for (i = 1; i <= n; i++)
                {
                    for (j = 1; j <= n; j++)
                    {
                        if (x[i] == j)
                            printf(" Q ");
                        else
                            printf(" . ");
                    }
                    printf("\n");
                }
            }
            else
            {
                nQueens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    nQueens(1, n);

    if (count == 0)
        printf("\nNo solution exists.\n");
    else
        printf("\nTotal Solutions = %d\n", count);

    return 0;
}