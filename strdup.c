#include "main.h"

/**
 *string_duplicate- function that mimics the strdup() function
 *@s: the input string to be duplicated
 *
 *Return: the duplicated string
 */

char *string_duplicate(const char *s)
{
size_t len = 0;
size_t i;
char *str_cpy;
while (s[len] != '\0')
{
len++;
}

str_cpy = malloc(len + 1);
if (!str_cpy)
{
return (NULL);
}

for (i = 0; i <= len; i++)
{
str_cpy[i] = s[i];
}
return (str_cpy);
}
