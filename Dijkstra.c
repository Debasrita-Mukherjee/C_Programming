#include <stdio.h>
#define INF 99999

int main() {
    int n, i, j, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            // Replace 0 with INF for no edge (except diagonal)
            if(i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    int dist[n], visited[n];

    for(i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(i = 0; i < n - 1; i++) {
        int min = INF, u = -1;

        // Find the unvisited vertex with minimum distance
        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances of adjacent vertices
        for(j = 0; j < n; j++) {
            if(!visited[j] &&
               graph[u][j] != INF &&
               dist[u] + graph[u][j] < dist[j]) {

                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from source vertex %d:\n", source);
    printf("Vertex\tDistance\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}