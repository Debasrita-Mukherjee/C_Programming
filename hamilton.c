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
   
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}


bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
       
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        } else {
            return false;
        }
    }

    
    for (int v = 1; v < V; v++) {
        // Check if this vertex can be added to the path
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, pos + 1) == true) {
                return true;
            }

            
            path[pos] = -1;
        }
    }

    
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