#include<stdio.h>
int pronic(int n);
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(pronic(n)){
        printf("It is a pronic number");
    }
    else{
        printf("It is not a pronic number");
    }
    return 0;
}
int pronic(int n){
    int i;
    for(i=0; i<=n; i++){
        if(i*(i+1)==n){
            return 1;
        }

    }
}