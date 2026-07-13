#include <stdio.h>

int graph[10][10], color[10];
int n, m;

// Function to check if current color can be assigned
int isSafe(int v, int c)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

// Backtracking function
int graphColoring(int v)
{
    int c;

    if (v == n)
        return 1;

    for (c = 1; c <= m; c++)
    {
        if (isSafe(v, c))
        {
            color[v] = c;

            if (graphColoring(v + 1))
                return 1;

            color[v] = 0; // Backtrack
        }
    }

    return 0;
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++)
        color[i] = 0;

    if (graphColoring(0))
    {
        printf("\nSolution Exists\n");
        printf("Assigned Colors:\n");

        for (i = 0; i < n; i++)
        {
            printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
        }
    }
    else
    {
        printf("\nSolution does not exist.");
    }

    return 0;
}