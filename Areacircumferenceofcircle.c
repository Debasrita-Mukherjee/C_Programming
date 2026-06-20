#include<stdio.h>
int main(){
    int r;
    printf("Enter the radius: ");
    scanf("%d",&r);
    float pi=3.14;
    float area = pi*r*r;
    float circumference = 2*pi*r;
    printf("Area of the Circle: %f \n ",area);
    printf("Circumference of the circle: %f",circumference);


    return 0;
}