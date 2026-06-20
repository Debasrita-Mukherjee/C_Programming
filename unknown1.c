#include <stdio.h>
// Function to calculate the value of f(x) = x^2 + 1
float f(float x) {
return (x * x + 1);
}
// Function to calculate area using the Trapezoidal Rule
float calculateArea(float lower_limit, float upper_limit, int n) {
float area = 0.0, x, h;
int i;
// Calculate the width of each trapezoid
h = (upper_limit - lower_limit) / n;
// Calculate the area using trapezoidal rule
for (i = 0; i < n; i++) {
x = lower_limit + i * h;
area += 0.5 * (f(x) + f(x + h)) * h;
}
return area;
}
int main() {
float lower_limit, upper_limit;
int n;
// Input from user
printf("Enter the lower limit (A): ");
scanf("%f", &lower_limit);
printf("Enter the upper limit (B): ");
scanf("%f", &upper_limit);
printf("Enter the number of trapezoids: ");
scanf("%d", &n);
// Calculate and print the area
float result = calculateArea(lower_limit, upper_limit, n);
printf("Approximate area under the curve f(x) = x^2 + 1 is: %.4f\n", result);
return 0;
}
