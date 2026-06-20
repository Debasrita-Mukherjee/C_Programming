#include <stdio.h>
#include <string.h>
int main() {
char text[500], word[50];
int count = 0;
char *token;
printf("Enter the text:\n");
fgets(text, sizeof(text), stdin);
printf("Enter the word to find:\n");
scanf("%s", word);
token = strtok(text, " ,.\n");
while (token != NULL) {
if (strcmp(token, word) == 0) {
count++;
}
token = strtok(NULL, " ,.\n");
}
printf("The word '%s' occurred %d times.\n", word, count);
return 0;
}
