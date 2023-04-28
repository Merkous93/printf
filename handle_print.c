#include "main.h"
/**
*handle_print - fct to print
*@format: char
*@i: int
*@list: arg
*@buffer: array
*@flags: int
*@width: int
*@precision: int
*@len: int
*Return: 1/2
*/
int handle_print(const char *format, int *i, va_list list,
		char buffer[], int flags, int width,
		int precision, int len)
{
int x, unknow_len = 0, printed_chars = -1;
format_t format_types[] = {
	{'c', print_char}, {'s', print_string},
	{'%', print_pourcentage}, {'i', print_int},
	{'d', print_int}, {'b', print_binary},
	{'u', print_unsgnd}, {'o', print_octal},
	{'x', print_hexadecimal}, {'X', print_hexa_upper},
	{'p', print_pointer}, {'S', print_non_printable},
	{'r', print_reverse}, {'R', print_rot13},
	{'\0', NULL}};
	for (x = 0; format_types[x].format != '\0'; x++)
	{
		if (format[*i] == format_types[x].format)
			return (format_types[x].fn(list, buffer, flags,
				width, precision, len));
	}
	if (format_types[x].format == '\0')
	{
		if (format[*i] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*i - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (format[*i] != ' ' && format[*i] != '%')
				--(*i);
			if (format[*i] == ' ')
				--(*i);
			return (1);
		}
		unknow_len += write(1, &format[*i], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
