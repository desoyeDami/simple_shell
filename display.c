#include "main.h"

/**
 *display- function that displays a prompt and recieved the typed input
 *
 *Return: the typed inputs
 */

char *display(void)
{
ssize_t display;
char *line = NULL;
size_t n = 0;

display = write(1, "$ ", 2);
if (display == -1)
{
	perror("Error writing");
}

if (getline(&line, &n, stdin) == -1)
{
	free(line);
	if (write(1, "\n", 1) == -1)
{
	perror("Error writing");
};
exit(0);
}
return (line);
}
