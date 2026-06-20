#include<stdio.h>
#include<math.h>
int main(){
    int num, ori, rev=0, remain, n=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    ori=num;
    while(ori!=0){
        ori=ori/10;
        n++;
    }
    while(ori!=0){
        remain=ori%10;
        rev= rev+ pow(remain,n);
        ori=ori/10;
    }
    if(rev==num){
        printf("amstrong");
    }
    else{
        printf("not");
        
    }
    return 0;
}