#include "main.h"

/**
 *str_compare- A customized strcmp() function
 *@s1: the first string
 *@s2: the second string
 *Return: integer
 */
int str_compare(const char *s1, const char *s2)
{
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
