#include <stdio.h>

#define INF 999999
#define MAX_CITIES 15 // Set to 15 to keep the memoization array safe in memory

int n;
int dist[MAX_CITIES][MAX_CITIES];
int memo[1 << MAX_CITIES][MAX_CITIES];

// TSP solver function using bitmasking and dynamic programming
int tsp(int mask, int pos) {
    // Base Case: If all cities have been visited, return the cost to go back to starting city (0)
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    // If this subproblem has already been solved, return the stored result
    if (memo[mask][pos] != -1) {
        return memo[mask][pos];
    }

    int min_cost = INF;

    // Try to visit all next unvisited cities
    for (int next_city = 0; next_city < n; next_city++) {
        // Check if the next_city has not been visited yet
        if ((mask & (1 << next_city)) == 0) {
            int new_cost = dist[pos][next_city] + tsp(mask | (1 << next_city), next_city);
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }

    return memo[mask][pos] = min_cost;
}

int main() {
    printf("Enter the number of cities (Max %d): ", MAX_CITIES);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_CITIES) {
        printf("Invalid number of cities.\n");
        return 1;
    }

    printf("Enter the distance matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Initialize the memoization table with -1
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            memo[i][j] = -1;
        }
    }

    // Start from city 0, with only city 0 visited (mask = 1)
    int total_min_cost = tsp(1, 0);

    printf("\nThe minimum possible travel cost is: %d\n", total_min_cost);

    return 0;
}