#include <stdio.h>

int main() {
    int rows, i, j, space;

    rows = 5;

    for (i = 1; i <= rows; i++) {
    
        for (space = 1; space <= rows - i; space++) {
            printf("  ");
        }

        for (j = 1; j <= 2 * i - 1; j++) {
            if(j%2==0){
                printf("  ");
            }
            else{
                printf("* ");
            }
        }
    
        printf("\n");
    }
    return 0;
}