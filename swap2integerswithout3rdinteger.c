#include<stdio.h>
int main(){
    int x;
    printf("Enter the value of x: ");
    scanf("%d",&x);
    int y;
    printf("Enter the value of y: ");
    scanf("%d",&y);
    printf("%d %d\n",x,y);
    x=x+y;
    y=x-y;
    x=x-y;
    printf("The new values of x is %d and y is %d",x,y);
    return 0;
}