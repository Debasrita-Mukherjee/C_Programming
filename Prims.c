#include <stdio.h>
#include <limits.h>

#define V 5


int main() {
int graph[V][V] = {
{0, 2, 0, 6, 0},
{2, 0, 3, 8, 5},
{0, 3, 0, 0, 7},
{6, 8, 0, 0, 9},
{0, 5, 7, 9, 0}
};


int selected[V] = {0}; int edge_count = 0;

selected[0] = 1;


printf("Edge : Weight\n");
 
while (edge_count < V - 1) { int min = INT_MAX;
int x = -1, y = -1;


for (int i = 0; i < V; i++) { if (selected[i]) {
for (int j = 0; j < V; j++) {
if (!selected[j] && graph[i][j] != 0) { if (graph[i][j] < min) {
min = graph[i][j]; x = i;
y = j;
}
}
}
}
}


if (x != -1 && y != -1) {
printf("%d - %d : %d\n", x, y, graph[x][y]); selected[y] = 1;
edge_count++;
}
}


return 0;
}
