#include<stdio.h>
int main(){
    int n;
    printf("Enter the no of rows: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-1; j++){
            printf(" ");
        }
        for(int k=1; k<=i; k++){
            printf("*");

        }
        for(int q=1; q<=n+1-i; q++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
  }