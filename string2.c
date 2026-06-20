#include <stdio.h>
int my_strlen(char *str) {
int len = 0;
while (str[len] != '\0') len++;
return len;
}
void my_strcpy(char *dest, char *src) {
while (*src) *dest++ = *src++;
*dest = '\0';
}
void my_strcat(char *dest, char *src) {
while (*dest) dest++;
while (*src) *dest++ = *src++;
*dest = '\0';
}
int my_strcmp(char *s1, char *s2) {
while (*s1 && (*s1 == *s2)) {
s1++; s2++;
}
return *(unsigned char *)s1 - *(unsigned char *)s2;
}
int main() {
char a[100] = "Hello", b[100] = "World", c[100];
printf("Length of a: %d\n", my_strlen(a));
my_strcpy(c, a);
printf("Copied string: %s\n", c);
my_strcat(a, b);
printf("Concatenated string: %s\n", a);
printf("Comparison of a and b: %d\n", my_strcmp(a, b));
return 0;
}