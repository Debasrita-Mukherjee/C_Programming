#include<stdio.h>
int main(){
    int CP;
    printf("Enter Cost Price : ");
    scanf("%d",&CP);
    int SP;
    printf("Enter Selling Price : ");
    scanf("%d",&SP);
    if(SP>CP){
        printf("profit");
    }
    if(CP>SP){
        printf("loss");
    }
    if(SP == CP){
        printf("NO PROFIT NO LOSS");
    }
}