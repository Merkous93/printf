#include "main.h"
/**
 * handle_width - handle field width
 *@format: char
 *@i: int
 *@list: arg
 *Return: Width
 */
int handle_width(const char *format, int *i, va_list list)
{
int x, width;
width = 0;
	for (x = *i + 1; format[x] != '\0'; x++)
	{
		if (_isdigit(format[x]))
		{
			width *= 10;
			width += format[x] - 0;
		}
		else if (format[x] == '*')
		{
			x++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = x - 1;
	return (width);
}
