#include<stdio.h>
int main(){
    int arr[]={5,4,3,2};
    int n= sizeof(arr)/4;
    int product=1;
    for(int i =0; i<n; i++){
        product = product * arr[i];

    }
    printf("%d",product);
    return 0;
}