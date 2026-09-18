#include <stdio.h>

void printHourglass(int n) {
 
    for (int i = 0; i < n; i++) {
    
        for (int j = 0; j < i; j++)
            printf("  ");
        for (int j = 0; j < n - i; j++)
            printf("* ");
        printf("\n");
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < i; j++)
            printf("  ");
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