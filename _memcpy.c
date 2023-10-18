#include "main.h"

/**
 *_memcpy- copies memory src to dest
 *@dest: destination memory
 *@src: source memory
 *@n: counter
 *
 *Return: thedestination memory
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
size_t i;
char *curr_dest = (char *) dest;
const char *curr_src = (const char *) src;

for (i = 0; i < n; i++)
{
	curr_dest[i] = curr_src[i];
}
return (dest);
}
