#include <stdio.h>

int main() {
    int rows = 4; // Number of rows in the pattern
    int a = 0, b = 1, next;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            if(b<=34){
            printf("%d ", a);
            }
            next = a + b;
            a = b;
            b = next;
        }
        printf("\n");
    }

    return 0;
}