#include<stdio.h>
int main(){
    int m,n;
    printf("Enter the no of rows: ");
    scanf("%d", &m);
    printf("Enter the no of columns: ");
    scanf("%d",&n);
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(i==1||i==m||j==1||j==n){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}