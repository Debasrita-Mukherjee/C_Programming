#include <stdio.h>

int main() {
    int rows = 5;
    
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        
        // Print increasing numbers
        for (int j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        
        // Print decreasing numbers
        for (int j = 2; j <= i; j++) {
            printf("%d ", j);
        }
        
        printf("\n");
    }
    
    return 0;
}
