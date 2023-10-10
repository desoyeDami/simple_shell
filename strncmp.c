#include "main.h"

/**
 *strn_compare- function that mimics the strncmp() function
 *@s1: Characters in the destination memory
 *@s2: Characters in the source memory
 *@n: Number of characters to be compared
 *
 *Return: success (0)
 */
int strn_compare(const char *s1, const char *s2, size_t n)
{
while (n)
{
if (*s1 != *s2 || !*s1 || !*s2)
{
/* Cast to unsigned char to handle negative chars correctly */
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
s1++;
s2++;
n--;
}
return (0);
}
