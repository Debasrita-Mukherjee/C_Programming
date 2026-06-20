#include<stdio.h>
int main(){
    float Fahrenheit, Celsius;
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &Fahrenheit);
    Celsius=((Fahrenheit-32)*5)/9;
    printf("The temperature in celsius: %f",Celsius);
    printf("\n");
    printf("Enter the temperature in Celsius : ");
    scanf("%f", &Celsius);
    Fahrenheit=((9*Celsius)/5)+32;
    printf("The temperature in  Fahrenheit: %f", Fahrenheit);
    return 0;
}