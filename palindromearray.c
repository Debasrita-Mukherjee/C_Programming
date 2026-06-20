#include<stdio.h>
int main(){
    int n;
    printf("Enter the no of terms: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the inputs of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);

    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    int brr[n];
    for(int i=0; i<n; i++){
        brr[i]= arr[n-1-i];
    }
    for(int i=0; i<n; i++){
        printf("%d ", brr[i]);
    }
    printf("\n");
    if(arr[n]==brr[n]){
        printf("Palindrome");
    }
    else{
        printf("Not a Palindrome");  
    }
    
    return 0;
}