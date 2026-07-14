#include <stdio.h>

#define INF 99999

int main() {
    int n, i, j, k;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    printf("Enter the adjacency matrix:\n");
    printf("(Enter 0 if there is no direct edge, except on the diagonal)\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if(i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    printf("\nShortest Distance Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(graph[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}