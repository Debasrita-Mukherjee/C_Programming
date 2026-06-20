#include<stdio.h>
int binary(int x);
int main(){
    int x;
    printf("Enter a Decimal Number: ");
    scanf("%d", &x);
    int bin= binary( x);
    printf("The binary no is %d",bin);
}
int binary(int x){
    int bin=0;
    int i=1;
    while(x>0){
        int r=x%2;
        x=x/2;
        bin=bin+i*r;
        i=i*10;
    }
    return bin;
}