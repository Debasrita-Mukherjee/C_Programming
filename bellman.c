#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int source;
    int destination;
    int weight;
};

// Structure to represent a connected, directed, and weighted graph
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    struct Edge* edge; // Array of edges
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
}

// Utility function to print the calculated distances
void printSolution(int dist[], int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            printf("%d \t\t INF\n", i);
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

void bellmanFord(struct Graph* graph, int source) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Step 1: Initialize distances from source to all other vertices as INFINITY
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Step 2: Relax all edges |V| - 1 times.
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            
            // If the source vertex distance is not INF and the new path is shorter
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles. 
    // If we can still find a shorter path, then a cycle exists.
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative-weight cycle! Shortest paths cannot be reliably calculated.\n");
            return;
        }
    }

    // If no negative cycle is found, print the distances
    printSolution(dist, V);
}

int main() {
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // Adding edge 0-1
    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = -1;

    // Adding edge 0-2
    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 4;

    // Adding edge 1-2
    graph->edge[2].source = 1;
    graph->edge[2].destination = 3;
    graph->edge[2].weight = 3;

    // Adding edge 1-3
    graph->edge[3].source = 1;
    graph->edge[3].destination = 4;
    graph->edge[3].weight = 2;

    // Adding edge 1-4
    graph->edge[4].source = 3;
    graph->edge[4].destination = 2;
    graph->edge[4].weight = 5;

    // Adding edge 3-2
    graph->edge[5].source = 3;
    graph->edge[5].destination = 1;
    graph->edge[5].weight = 1;

    // Adding edge 4-3
    graph->edge[6].source = 4;
    graph->edge[6].destination = 3;
    graph->edge[6].weight = -3;
    
    // Adding edge 2-4
    graph->edge[7].source = 1;
    graph->edge[7].destination = 2;
    graph->edge[7].weight = 3;

    int source_vertex = 0;
    bellmanFord(graph, source_vertex);

    // Free allocated memory
    free(graph->edge);
    free(graph);

    return 0;
}