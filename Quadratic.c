#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, discriminant, root1, root2, realPart, imagPart;

    // Input coefficients
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calculate discriminant
    discriminant = (b * b) - (4 * a * c);

    // Check the nature of roots using if-else
    if (discriminant > 0) {
        // Two distinct real roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and distinct: %.2lf and %.2lf\n", root1, root2);
    } 
    else if (discriminant == 0) {
        // One real and equal root
        root1 = root2 = -b / (2 * a);
        printf("Roots are real and equal: %.2lf and %.2lf\n", root1, root2);
    } 
    else {
        // Complex conjugate roots
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex and imaginary: %.2lf + %.2lfi and %.2lf - %.2lfi\n", realPart, imagPart, realPart, imagPart);
    }

    return 0;
}