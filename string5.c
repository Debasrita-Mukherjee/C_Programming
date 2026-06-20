#include <stdio.h>
#include <ctype.h>
int main() {
char str[100];
int i = 0;
printf("Enter a name: ");
fgets(str, sizeof(str), stdin);
printf("Acronym: ");
// Print first character if it's a letter
if (isalpha(str[0])) {
printf("%c.", toupper(str[0]));
}
// Traverse the string
while (str[i] != '\0') {
if (str[i] == ' ' && isalpha(str[i + 1])) {
printf("%c.", toupper(str[i + 1]));
}
i++;
}
printf("\n");
return 0;
}