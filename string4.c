#include <stdio.h>
int is_vowel(char ch) {
// Check if character is a vowel (both lowercase and uppercase)
return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}
int main() {
char str[100], result[100];
int i = 0, j = 0;
printf("Enter a sentence: ");
fgets(str, sizeof(str), stdin); // Read full line including spaces
while (str[i] != '\0') {
if (!is_vowel(str[i])) {
result[j] = str[i];
j++;
}
i++;
}
result[j] = '\0'; // Null-terminate the result string
printf("Sentence after deleting vowels: %s", result);
return 0;
}