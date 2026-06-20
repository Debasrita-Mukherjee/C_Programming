#include <stdio.h>

int main() {
    int rows = 4; // Maximum row count in the upper half

    // Upper Half of the Pattern
    for (int i = 1; i <= rows; i++) {
        // Print increasing numbers
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        // Print decreasing numbers
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }

    // Lower Half of the Pattern
    for (int i = rows - 1; i >= 1; i--) {
        // Print increasing numbers
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        // Print decreasing numbers
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}