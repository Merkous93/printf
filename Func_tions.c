#include "main.h"
/**
 * print_pointer - Print the value of a pointer variable
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	char extra_c = 0, padd = ' ';
	int i = BUFFER_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(len);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[i--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & ZERO) && !(flags & TIRET))
		padd = '0';
	if (flags & PLUS)
		extra_c = '+', length++;
	else if (flags & SPACE)
		extra_c = ' ', length++;

	i++;

	return (write_pointer(buffer, i, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Print ascii
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(len);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (_isprintable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - Print reverse string.
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	char *str;
	int i, count;
count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(len);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = "(Null)";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13 - Print a string in rot13.
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(len);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
