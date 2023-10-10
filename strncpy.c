#include "main.h"

/**
 *strn_copy- function that mimics the strncpy() function
 *@dest: Characters in the destination memory
 *@src: Characters in the source memory
 *@n: Number of characters to be copied
 *
 *Return: the tokens
 */
char *strn_copy(char *dest, const char *src, size_t n)
{
size_t i;
for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[i] = src[i];
}
/* If src has less than n characters, fill the rest with null bytes */
while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}
