#include "main.h"
void print_buffer(char buffer[], int *buff);
/**
*_printf - Printf function
*@format: const char.
* Return: Printed char.
*/
int _printf(const char *format, ...)
{
int i, printed, printed_chars, flags, width, precision, len, buff;
va_list list;
char buffer[BUFFER_SIZE];

printed = printed_chars = buff = 0;
if (format == NULL)
	return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
	if (format[i] != '%')
	{
		buffer[buff++] = format[i];
		if (buff == BUFFER_SIZE)
			print_buffer(buffer, &buff);
		printed_chars++;
	}
	else
	{
		print_buffer(buffer, &buff);
		flags = handle_flags(format, &i);
		width = handle_width(format, &i, list);
		precision = handle_precision(format, &i, list);
		len = handle_len(format, &i);
		++i;
		printed = handle_print(format, &i, list, buffer,
				flags, width, precision, len);
		if (printed == -1)
			return (-1);
		printed_chars += printed;
	}
}
print_buffer(buffer, &buff);
va_end(list);
return (printed_chars);
}

/**
 *print_buffer - Prints the contents of the buffer if it exist
 *@buffer: Array of chars
 *@buff: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff)
{
	if (*buff > 0)
		write(1, &buffer[0], *buff);
	*buff = 0;
}
