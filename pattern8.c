#include <stdio.h>

int main() {
    int rows, i, j, space;

    // Define the number of rows for the triangle
    rows = 5;

    // Outer loop for the number of rows
    for (i = 1; i <= rows; i++) {
        // Inner loop for spaces
        for (space = 1; space <= rows - i; space++) {
            printf("  ");
        }
        // Inner loop for stars
        for (j = 1; j <= 2 * i - 1; j++) {
            if(j%2==0){
                printf("  ");
            }
            else{
                printf("* ");
            }
        }
        // Print newline after each row
        printf("\n");
    }
    return 0;
}