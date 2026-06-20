#include<stdio.h>
int main(){
int size;
printf("Enter the size of the array: ");
scanf("%d",&size);
int arr[size],n,i,pos;
printf("Enter number of elements: ");
scanf("%d",&n);
printf("Enter %d elements :\n",n);
for(i=0; i<n; i++)
scanf("%d",&arr[i]);
printf("Enter position to delete (0 to %d ): ", n-1);
scanf("%d", &pos);
for(i=pos;i<n-1;i++)
arr[i]= arr[i+1];
n--;
printf("Array after deletion: \n");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
return 0;
} 
