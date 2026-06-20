#include<stdio.h>
int main (){
    int Year;
    printf("Enter a Year : ");
    scanf("%d",&Year);
    if(Year % 4 == 0){
        printf("It is a Leap Year");
    }
    else{
        printf("Not a Leap Year");
    }

    return 0;
}