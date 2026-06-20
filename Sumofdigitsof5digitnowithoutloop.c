#include <stdio.h>

int sum_of_digits(int num) {
    return (num % 10) + ((num / 10) % 10) + ((num / 100) % 10) + ((num / 1000) % 10) + ((num / 10000) % 10);
}

int main() {
    int num;
    printf("Enter a five-digit number: ");
    scanf("%d", &num);
    printf("Sum of digits: %d\n", sum_of_digits(num));
    return 0;
}
