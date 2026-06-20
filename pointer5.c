#include <stdio.h>
#include <string.h>
int main() {
char *arr[] = {"abc", "deh", "bac"};
char *temp;
int i, j;
for (i = 0; i < 3; i++) {
for (j = i + 1; j < 3; j++) {
if (strcmp(arr[i], arr[j]) > 0) {
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
}
printf("Sorted strings:\n");
for (i = 0; i < 3; i++) {
printf("%s\n", arr[i]);
}
return 0;
}