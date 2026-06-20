#include<stdio.h>
int fibonacci(int n){
if(n <= 1)
return n;
else
return fibonacci(n - 1)+fibonacci(n - 2);
}
int main(){
int n;
printf("Enter a number: ");
scanf("%d",&n);
printf("The fibonacci Series is:\n");
for(int i = 0; i < n; i++){
printf("\t %d",fibonacci(i));
}
return 0;
}