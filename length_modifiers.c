#include "main.h"
/**
*handle_len - handle the length modifiers
*@format: char
*@i: int
*Return: Length
*/
int handle_len(const char *format, int *i)
{
int x, len;
x = *i + 1;
len = 0;
	if (format[x] == 'l')
	{
		len = MAJ;
	}
	else if (format[x] == 'h')
	{
		len = MIN;
	}
	if (len == 0)
	{
		*i = x - 1;
	}
	else
		*i = x;
	return (len);
}
