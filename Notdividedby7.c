#include <stdio.h>

int main() {
    int n, i, count = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = 1; count < n; i++) {
        if (i % 7 != 0) {
            printf("%d\n", i);
            count++;
        }
    }

    return 0;
}