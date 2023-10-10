#include "main.h"

/**
 *get_path- function that gets the value of the PATH variable
 *
 *Return: value of the PATH variable
 */
char *get_path()
{
char **env = environ;
while (*env)
{
if (strn_compare(*env, "PATH=", 5) == 0)
{
return (*env + 5);
}
env++;
}
return (NULL);
}



/**
 *path- function that appends command to a PATH to creates an executable file
 *@cmd: the command to be appended to get its relative path
 *
 *Return: the executable file
 */
char *path(char *cmd)
{
char *token;
char *buf;
struct stat info;
char *PATH = string_duplicate(get_path());

if (PATH == NULL)
{
return (NULL);
}

buf = malloc(sizeof(char) * 1024);
if (!buf)
{
free(PATH);
return (NULL);
}

token = strtok(PATH, ":");
while (token)
{
strn_copy(buf, token, 1023);
strn_concat(buf, "/", 1023 - strlen(buf) - 1);
strn_concat(buf, cmd, 1023 - strlen(buf) - 1);

if (stat(buf, &info) == 0 && S_ISREG(info.st_mode))
{
free(PATH);
return (buf);
}

token = strtok(NULL, ":");
}

free(buf);
free(PATH);
return (NULL);
}
