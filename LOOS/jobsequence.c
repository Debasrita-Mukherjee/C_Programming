#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a Job
typedef struct {
    char id;      // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit if job is completed
} Job;

// Comparison function to sort jobs in descending order of profit
int compareJobs(const void* a, const void* b) {
    Job* temp1 = (Job*)a;
    Job* temp2 = (Job*)b;
    return (temp2->profit - temp1->profit);
}

// Function to find the maximum deadline
int findMaxDeadline(Job arr[], int n) {
    int max = arr[0].deadline;
    for (int i = 1; i < n; i++) {
        if (arr[i].deadline > max) {
            max = arr[i].deadline;
        }
    }
    return max;
}

void jobSequencing(Job arr[], int n) {
    // 1. Sort jobs by descending profit
    qsort(arr, n, sizeof(Job), compareJobs);

    int maxDeadline = findMaxDeadline(arr, n);

    // 2. Allocate tracking arrays based on max deadline
    bool* slot = (bool*)calloc(maxDeadline + 1, sizeof(bool));
    char* result = (char*)malloc((maxDeadline + 1) * sizeof(char));

    int totalProfit = 0;
    int jobCount = 0;

    // 3. Iterate through all sorted jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job from its deadline backwards
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == false) {
                slot[j] = true;          
                result[j] = arr[i].id;   
                totalProfit += arr[i].profit;
                jobCount++;
                break; 
            }
        }
    }

    // Print final sequence
    printf("\n--- Optimal Job Sequence ---\n");
    printf("Scheduled Sequence: ");
    for (int j = 1; j <= maxDeadline; j++) {
        if (slot[j]) {
            printf("%c ", result[j]);
        }
    }
    printf("\nTotal Jobs Scheduled: %d", jobCount);
    printf("\nMaximum Profit Earned: %d\n", totalProfit);

    free(slot);
    free(result);
}

int main() {
    int n;

    printf("Enter the number of jobs: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of jobs.\n");
        return 1;
    }

    // Dynamically allocate memory for n jobs
    Job* arr = (Job*)malloc(n * sizeof(Job));

    printf("\nEnter Job Details (ID Deadline Profit):\n");
    printf("Example: a 2 100\n\n");

    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        // Note the space before %c to skip any leftover newline characters in the buffer
        scanf(" %c %d %d", &arr[i].id, &arr[i].deadline, &arr[i].profit);
    }

    jobSequencing(arr, n);

    free(arr); // Clean up job array memory
    return 0;
}