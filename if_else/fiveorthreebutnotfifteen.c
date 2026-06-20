#include<stdio.h>
int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",n);
    if(n%5==0 || n%3==0){
        if(n%15==0){
            printf("Divisible by fifteen");
        }
        else{
            printf("Divisible by 3 or 5 but not fifteen");
        }
    }
    else{
        printf("Not divisible by 3 or 5");
    }
    return 0;
}