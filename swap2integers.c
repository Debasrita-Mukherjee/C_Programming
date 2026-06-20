#include<stdio.h>
int main(){
    int x;
    printf("Enter the value of x:");
    scanf("%d",&x);
    int y;
    printf("Enter the value of y:");
    scanf("%d",&y);
    printf("%d %d\n",x,y);
    int d=x;
    x=y;
    y= d;
    printf("The new values of x is %d and y is %d",x,y);
    return 0;
}