#include "main.h"

/**
 *tokenize- function that tokenize strings
 *@line: the input string to be tokenized
 *
 *Return: the tokens
 */
char **tokenize(char *line)
{
char *token;
char **buf;
int i = 0;

buf = malloc(sizeof(char *) * 1024);
if (!buf)
{
	perror("Error creating memory");
	exit(EXIT_FAILURE);
}

token = strtok(line, " \n\t");
while (token && i < 1023)
{
	buf[i] = string_duplicate(token);
	if (!buf[i])
	{
		perror("Error duplicating token");
		while (i > 0)
		{
			i--;
			free(buf[i]);
		}
		free(buf);
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \n\t");
	i++;
}
buf[i] = NULL;
return (buf);
}


/**
 *env_exit- function that executes the exit and env commands
 *@tokens: the commands to be executed
 *
 *Return: void
 */
void env_exit(char **tokens) /* Handle exit and environmens */
{
int i;
if (tokens[0] && str_compare(tokens[0], "env") == 0) /* Handle environments */
	print_env();
if (tokens[0] && str_compare(tokens[0], "exit") == 0)  /* Handle exit */
{
int exit_status;
i = 0;
exit_status = 0;

if (tokens[1] != NULL)
{
	exit_status = ato_int(tokens[1]);
}
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);  /* Clean up the allocated memory for tokens */
	exit(exit_status);  /* Exit the shell */
}
}


/**
 *set_unsetenv- function that executes the setenv() and unsetenv() functions
 *@tokens: array of strings
 *
 *Return: success 0
 */
int set_unsetenv(char **tokens)
{
if (tokens[0] && str_compare(tokens[0], "setenv") == 0)
{
	_setenv(tokens);
	return (1);
}
else if (tokens[0] && str_compare(tokens[0], "unsetenv") == 0)
{
	_unsetenv(tokens);
	return (1);
}
return (0);
}


/**
 *execute- function that executes a program
 *@tokens: commands to be executed
 *@shell_name: the name of the program
 *
 *Return: void
 */
void execute(char **tokens, char *shell_name)
{
pid_t pid;
int status;
char *full_path = NULL;

env_exit(tokens);
if (set_unsetenv(tokens))
	return;
pid = fork();
if (pid == -1)
{
	perror("Error forking");
	exit(EXIT_FAILURE);
}
if (pid == 0)
{
if (tokens[0] == NULL)
	exit(0);
if (execve(tokens[0], tokens, environ) == -1)
{
	full_path = path(tokens[0]);
	if (full_path)
	{
		if (execve(full_path, tokens, environ) == -1)
			perror(shell_name); /* Display error if command cannot be executed */
		free(full_path);  /* Free the memory if path() allocated it */
	} else
	{
		perror(shell_name); /* Display error if command not found */
	}
}
	exit(EXIT_FAILURE);
} else
{
	waitpid(pid, &status, 0);
}
}
