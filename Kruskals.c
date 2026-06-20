#include <stdio.h>
#include <stdlib.h>

#define V 4
#define E 5


typedef struct { int src;
int dest; int weight;
} Edge;


int parent[V]; int rank[V];

int find(int i) {
if (parent[i] != i)
parent[i] = find(parent[i]); return parent[i];
}


void unionSet(int u, int v) { int root_u = find(u);
 
int root_v = find(v);


if (rank[root_u] < rank[root_v]) { parent[root_u] = root_v;
} else if (rank[root_u] > rank[root_v]) { parent[root_v] = root_u;
} else {
parent[root_v] = root_u; rank[root_u]++;
}
}


int compare(const void *a, const void *b) { Edge *e1 = (Edge *)a;
Edge *e2 = (Edge *)b;
return e1->weight - e2->weight;
}


int main() {
Edge edges[E] = {
{0, 1, 10},
{0, 2, 6},
{0, 3, 5},
{1, 3, 15},
{2, 3, 4}
};


for (int i = 0; i < V; i++) { parent[i] = i;
rank[i] = 0;
 
}


qsort(edges, E, sizeof(Edge), compare);


printf("Edge : Weight\n");


int count = 0;
for (int i = 0; i < E && count < V - 1; i++) { int u = edges[i].src;
int v = edges[i].dest;


if (find(u) != find(v)) {
printf("%d - %d : %d\n", u, v, edges[i].weight); unionSet(u, v);
count++;
}
}


return 0;
}
