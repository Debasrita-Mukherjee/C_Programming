#include <stdio.h>
#include <stdbool.h>

#define V 5

void printSolution(int path[]) {
    printf("Hamiltonian Cycle exists! Here is one valid path:\n");
    for (int i = 0; i < V; i++) {
        printf(" %d ->", path[i]);
    }
   
    printf(" %d\n", path[0]);
}

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

// A recursive utility function to solve the Hamiltonian Cycle problem
bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
        // And if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        } else {
            return false;
        }
    }

    // Try different vertices as the next candidate in the Hamiltonian Cycle
    for (int v = 1; v < V; v++) {
        // Check if this vertex can be added to the path
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, pos + 1) == true) {
                return true;
            }

            // If adding vertex v doesn't lead to a solution, remove it (Backtrack)
            path[pos] = -1;
        }
    }

    // If no vertex can be added to the path constructed so far
    return false;
}


bool hamCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }

   
    path[0] = 0;
    
    if (hamCycleUtil(graph, path, 1) == false) {
        printf("\nHamiltonian Cycle does not exist in this graph.\n");
        return false;
    }

    printSolution(path);
    return true;
}

int main() {
    /* Create the following graph
      (0)-------(1)-------(2)
       |       /   \       |
       |      /     \      |
       |     /       \     |
       |    /         \    |
      (4)---------------(3)    
    */
    bool graph1[V][V] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
    };

   
    hamCycle(graph1);

    return 0;
}