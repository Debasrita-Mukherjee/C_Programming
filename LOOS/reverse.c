#include<stdio.h>
int main(){
    int n;
    
    printf("Enter a number: ");
    scanf("%d",&n);
    int r=0;
    
    while(n>0){
        r=(n%10)+r;
        r=r*10;
        n=n/10;
    }
    r=r/10;
     int sum= r+n;
    printf("The reverse number is %d",r);
    printf("The sum is %d",sum);

    return 0;
}