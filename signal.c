#include "main.h"

/**
 *handle_sig- function that exits a shell  when a signal is recieved
 *@sig: the input signal being listened to
 *
 *Return: (void)
 */
void handle_sig(int sig)
{
if (write(1, "\n", 1) == -1)
{
perror("Error writing");
}
(void)sig;
exit(0);
}
