#include <stdio.h>
int findMax(int *a, int *b, int *c) {
int max = *a;
if (*b > max)
max = *b;
if (*c > max)
max = *c;
return max;
}
int main() {
int x, y, z;
printf("Enter three numbers: ");
scanf("%d %d %d", &x, &y, &z);
int max = findMax(&x, &y, &z);
printf("The maximum number is: %d\n", max);
return 0;
}