#include<stdio.h>
int main (){
    int dividend,divisor;
    printf("Enter dividend : ");
    scanf("%d", &dividend);
    printf("Enter divisor : ");
    scanf("%d", &divisor);
    int q = dividend/divisor;
    int r = dividend - (divisor*q);
    printf("The remainder when %d is divided by %d is : %d", dividend, divisor, r);
    return 0;
}