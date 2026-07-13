#include <stdio.h>

#define INF 999999
#define CITIES 4

// Adjacency matrix representing the distances between 4 cities
int dist[CITIES][CITIES] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

// Memoization table to store results of subproblems
// Rows = 2^CITIES (all possible visited combinations), Columns = CITIES (current city)
int memo[1 << CITIES][CITIES];

// TSP solver function using bitmasking and dynamic programming
int tsp(int mask, int pos) {
    // Base Case: If all cities have been visited, return the cost to go back to starting city (0)
    if (mask == (1 << CITIES) - 1) {
        return dist[pos][0];
    }

    // If this subproblem has already been solved, return the stored result
    if (memo[mask][pos] != -1) {
        return memo[mask][pos];
    }

    int min_cost = INF;

    // Try to visit all next unvisited cities
    for (int next_city = 0; next_city < CITIES; next_city++) {
        // Check if the next_city has not been visited yet
        if ((mask & (1 << next_city)) == 0) {
            // Move to the next city and update the mask
            int new_cost = dist[pos][next_city] + tsp(mask | (1 << next_city), next_city);
            
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }

    // Store and return the minimum cost for the current state
    return memo[mask][pos] = min_cost;
}

int main() {
    // Initialize the memoization table with -1 (representing unsolved)
    for (int i = 0; i < (1 << CITIES); i++) {
        for (int j = 0; j < CITIES; j++) {
            memo[i][j] = -1;
        }
    }

    // Start from city 0, with only city 0 visited (mask = 1 -> binary 0001)
    int initial_mask = 1;
    int starting_city = 0;
    
    int total_min_cost = tsp(initial_mask, starting_city);

    printf("The minimum possible travel cost is: %d\n", total_min_cost);

    return 0;
}