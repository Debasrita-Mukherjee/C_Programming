#include <stdio.h>

int main() {
    int num1, num2, num3, num4, num5;
    float average;

    printf("Enter five numbers: ");
    scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

    average = (num1 + num2 + num3 + num4 + num5) / 5.0;

    printf("Average of the five numbers is: %.2f\n", average);

    return 0;
}