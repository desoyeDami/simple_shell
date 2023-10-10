#include "main.h"

/**
 *strn_concat- function that mimics the strncat() function
 *@dest: the strings concatenated to the detination memo
 *@src: the string in the source
 *@n: the numbers of characters to be concatenanted
 *
 *Return: the tokens
 */
char *strn_concat(char *dest, const char *src, size_t n)
{
char *main = dest;

while (*dest)
{
dest++;
}

while (n-- && *src)
{
*dest++ = *src++;
}

*dest = '\0';

return (main);
}
