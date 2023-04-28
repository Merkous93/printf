#include "main.h"
/**
*handle_precision - fct to handle precision
*@format: char
*@i: int
*@list: arg
*Return: precision
*/
int handle_precision(const char *format, int *i, va_list list)
{
int x, precision;
x = *i + 1;
precision = -1;
	if (format[x] != '.')
	{
		return (precision);
	}
	precision = 0;
	for (x += 1; format[x] != '\0'; x++)
	{
		if (_isdigit(format[x]))
		{
			precision *= 10;
			precision += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = x - 1;
	return (precision);
}
