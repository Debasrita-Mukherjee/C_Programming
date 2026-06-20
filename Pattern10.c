#include <stdio.h>
int main(){
int i, j;
int rows = 7;
for (i = 1; i <= rows; i++){
if (i == 1 || i == rows){
printf(" 1 1\n");
} else if (i == 2 || i == rows - 1){
printf(" 333 333\n");
} else if (i == 3 || i == rows - 2){
printf("55555 55555\n");
} else {
printf("7777777777777\n");
}
}
return 0;
}