#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    int x[n];
    printf("Enter the inputs of array");
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
for(int i=0;i<n;i++){
printf("%d ",x[i]*x[i]);
}
    return 0;
}