#include <stdio.h>

void printHourglass(int n) {
    // Upper half
    for (int i = 0; i < n; i++) {
        // Print spaces
        for (int j = 0; j < i; j++)
            printf("  ");
        // Print stars
        for (int j = 0; j < n - i; j++)
            printf("* ");
        printf("\n");
    }

    // Lower half
    for (int i = n - 2; i >= 0; i--) {
        // Print spaces
        for (int j = 0; j < i; j++)
            printf("  ");
        // Print stars
        for (int j = 0; j < n - i; j++)
            printf("* ");
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printHourglass(n);
    return 0;
}