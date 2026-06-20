#include<stdio.h>
int main(){
    // float p,r,t,SI,CI;
    // printf("Enter the value of Principal: ");
    // scanf("%f",&p);
    // printf("Enter the value of interest ratio: ");
    // scanf("%f",&r);
    // printf("Enter the value of time: ");
    // scanf("%f",&t);
    // SI= (p*r*t)/100;
    // CI= (p*(1+r)^t);
    // printf("The Simple Interest is :%f ",SI);
    // printf("The Compound Interest is :%f ",CI);
    
int p,r,t;
printf("Enter the value od principal: ");
scanf("%d",&p);
printf("Enter the value of interest rato: ");
scanf("%d",&r);
printf("Enter the value of time: ");
scanf("%d",&t);
int CI;
CI=( p*(1+r)^t);
printf("compond interest is:%d\n",CI);
int SI;
SI= (p*r*t)/100;
printf("simple interest is:%d ",SI);

    return 0;
}