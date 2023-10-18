#include "main.h"

/**
 *_strlen- function that finds the length of a string
 *@str: the input string
 *
 *Return: length of string
 */

size_t _strlen(const char *str)
{
const char *len = str;

while (*len)
len++;

return (len - str);
}
