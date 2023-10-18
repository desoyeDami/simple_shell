#include "main.h"

/**
 *print_env- function that writes out the environment variables
 *
 *Return: void
 */
void print_env(void)
{
char **env = environ;
ssize_t w;
ssize_t n;
while (*env)
{
	w = write(STDOUT_FILENO, *env, _strlen(*env));
	if (w == -1)
		perror("Cannot write env");
	n = write(STDOUT_FILENO, "\n", 1);
	if (n == -1)
		perror("Cannot write new");
	env++;
}
}
