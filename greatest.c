#include <stdio.h> 
int main() 
{
 int a, b, c;
printf("Enter three numbers: "); 
scanf("%d %d %d", &a, &b, &c); 
int greatest = (a > b && a > c) ? a : (b > c ? b : c);  
printf("The greatest number is: %d\n", greatest);
 return 0; 
}
