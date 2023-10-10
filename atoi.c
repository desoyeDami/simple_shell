#include "main.h"

/**
 *ato_int- function that changes string to integer
 *@string: the input string to be changed to integer
 *
 *Return: the integers converted
*/
int ato_int(const char *string)
{
int integer_res = 0;
bool isNeg = false;

while (*string == ' ' || *string == '\t' || *string == '\n' ||
		*string == '\v' || *string == '\f' || *string == '\r')
{
	string++;
}

if (*string == '-')
{
	isNeg = true;
	string++;
} else if (*string == '+')
{
	string++;
}

	while (*string >= '0' && *string <= '9')
{
	integer_res = integer_res * 10 + (*string - '0');
	string++;
}

if (isNeg)
{
	integer_res = -integer_res;
}
	return (integer_res);
}
