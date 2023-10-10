#include "main.h"

/**
 *main- main function that runs a simple program
 *@ac: number of arguments
 *@av: array of strings
 *
 *Return: success (0)
 */
int main(int ac, char **av)
{
int i;
size_t n = 0;
char *input = NULL;
char **tokens;
(void)ac;

signal(SIGINT, handle_sig);
if (isatty(STDIN_FILENO)) /* Check if stdin is a terminal (interactive mode) */
{
while (1)
{
input = display();
tokens = tokenize(input);
execute(tokens, av[0]);
free(input);
for (i = 0; tokens[i]; i++)
{
	free(tokens[i]);
}
free(tokens);
}
}
else  /* Non-interactive mode */
{
if (getline(&input, &n, stdin) == -1)
{
perror("Error reading input");
exit(EXIT_FAILURE);
};  /* Reading input from the pipe */
tokens = tokenize(input);
execute(tokens, av[0]);
free(input);
for (i = 0; tokens[i]; i++)
{
free(tokens[i]);
}
free(tokens);
}
return (0);
}
