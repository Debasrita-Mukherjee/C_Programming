#include<stdio.h>
#include<math.h>
int power(int base, int exp);
int main(){
    int b, e;
    printf("enter base and exp: ");
    scanf("%d %d", &b, &e);
    int value= power(b,e);
    printf("value is %d \n", value);
    return 0;
}
int power(int base, int exp){
    int c;
    c= pow(base, exp);
    return c;
}