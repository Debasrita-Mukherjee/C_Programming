#include <stdio.h>

struct Edge {
    int src, dest, weight;
};

int main() {
    int V, E, i, j, source;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter source, destination and weight of each edge:\n");
    for(i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[V];

    // Initialize distances
    for(i = 0; i < V; i++)
        dist[i] = 99999;

    dist[source] = 0;

    // Relax all edges V-1 times
    for(i = 1; i <= V - 1; i++) {
        for(j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if(dist[u] != 99999 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for(j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if(dist[u] != 99999 && dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle.\n");
            return 0;
        }
    }

    printf("\nShortest distances from source vertex %d:\n", source);
    printf("Vertex\tDistance\n");

    for(i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}