#include<stdio.h>
int findGCD(int a, int b);
int main(){
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1,&num2);
    int gcd= findGCD(num1, num2);
    printf("Gcd of %d and %d is %d", num1,num2,gcd);
    return 0;
}
int findGCD(int num1, int num2){
    int gcd, i;
    for(int i=1; i<=num1 && i<=num2; i++){
        if(num1%i==0 && num2%i==0){
            gcd=i;

        }
}
return gcd;
}