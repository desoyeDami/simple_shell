#include "main.h"

/**
 *_setenv- function that set an environment variable
 *@tokens: the input array of strings
 *
 *Return: (void)
 */
void _setenv(char **tokens)
{
char *token = tokens[1];
char *ntoken = tokens[2];

if (!token || !ntoken)
{
if (write(STDERR_FILENO, "Incomplete Arguments\n", 22) == -1)
{
perror("Error writing setenv errmsg");
};
return;
}

if (setenv(token, ntoken, 1) != 0)
{
if (write(STDERR_FILENO, "Environment variable not set\n", 30) == -1)
{
perror("Error writing setenv errmsg");
};
}
}



/**
 *_unsetenv- function that unset an environment variable
 *@tokens: the input array of strings
 *
 *Return: (void)
 */
void _unsetenv(char **tokens)
{
char *token = tokens[1];

if (!token)
{
if (write(STDERR_FILENO, "Incomplete Arguments\n", 22) == -1)
{
perror("Error writing unsetenv errmsg");
};
return;
}

if (unsetenv(token) != 0)
{
if (write(STDERR_FILENO, "Environment variable not set\n", 30) == -1)
{
perror("Error writing unsetenv errmsg");
};
}
}
