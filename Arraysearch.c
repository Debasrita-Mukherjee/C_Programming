#include<stdio.h>
#include<stdbool.h>
int main(){
    int arr[]={18,20,78,90,42};
    int n= sizeof(arr)/4;
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    int x=20;
    bool flag;
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            flag=true;
            break;
        }
        else{
            flag= false;
            break;
        }
    }
    if(flag==true) printf("%d exists!",x);
    else printf("%d does not exists!",x);
    return 0;
}