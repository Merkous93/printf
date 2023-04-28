#include "main.h"
/**
 * handle_char - Print a string
 * @c: char
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int handle_char(char c, char buffer[],
	int flags, int width, int precision, int len)
	{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(len);

	if (flags & ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER_SIZE - i - 2] = padd;

		if (flags & TIRET)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Print a string
  * @i: int
*@_isnegative: int
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int write_number(int _isnegative, int i, char buffer[],
	int flags, int width, int precision, int len)
{
	int length = BUFFER_SIZE - i - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(len);

	if ((flags & ZERO) && !(flags & TIRET))
		padd = '0';
	if (_isnegative)
		extra_ch = '-';
	else if (flags & PLUS)
		extra_ch = '+';
	else if (flags & SPACE)
		extra_ch = ' ';

	return (write_num(i, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @i: int
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: int
 * @length: int
 * @padd: char
 * @extra_c: char
 *
 * Return: Number of printed chars.
 */
int write_num(int i, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int x, padd_start = 1;

	if (prec == 0 && i == BUFFER_SIZE - 2 && buffer[i] == '0' && width == 0)
		return (0);
	if (prec == 0 && i == BUFFER_SIZE - 2 && buffer[i] == '0')
		buffer[i] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--i] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (x = 1; x < width - length + 1; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & TIRET && padd == ' ')
		{
			if (extra_c)
				buffer[--i] = extra_c;
			return (write(1, &buffer[i], length) + write(1, &buffer[1], x - 1));
		}
		else if (!(flags & TIRET) && padd == ' ')
		{
			if (extra_c)
				buffer[--i] = extra_c;
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[i], length));
		}
		else if (!(flags & TIRET) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], x - padd_start) +
				write(1, &buffer[i], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--i] = extra_c;
	return (write(1, &buffer[i], length));
}

/**
 * write_unsgnd - Write an unsgnd number
 * @_isnegative: int
 * @i: int
 * @buffer: array
 * @flags: int
 * @width: int
 * @precision: int
 * @len: int
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int _isnegative, int i,
	char buffer[],
	int flags, int width, int precision, int len)
{
	int length = BUFFER_SIZE - i - 1, x = 0;
	char padd = ' ';

	UNUSED(_isnegative);
	UNUSED(len);

	if (precision == 0 && i == BUFFER_SIZE - 2 && buffer[i] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--i] = '0';
		length++;
	}

	if ((flags & ZERO) && !(flags & TIRET))
		padd = '0';

	if (width > length)
	{
		for (x = 0; x < width - length; x++)
			buffer[x] = padd;

		buffer[x] = '\0';

		if (flags & TIRET)
		{
			return (write(1, &buffer[i], length) + write(1, &buffer[0], x));
		}
		else
		{
			return (write(1, &buffer[0], x) + write(1, &buffer[i], length));
		}
	}

	return (write(1, &buffer[i], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: array
 * @i: int
 * @length: int
 * @width: int
 * @flags: int
 * @padd: char
 * @extra_c: char
 * @padd_start: int
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int i, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int x;

	if (width > length)
	{
		for (x = 3; x < width - length + 3; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & TIRET && padd == ' ')
		{
			buffer[--i] = 'x';
			buffer[--i] = '0';
			if (extra_c)
				buffer[--i] = extra_c;
			return (write(1, &buffer[i], length) + write(1, &buffer[3], x - 3));
		}
		else if (!(flags & TIRET) && padd == ' ')
		{
			buffer[--i] = 'x';
			buffer[--i] = '0';
			if (extra_c)
				buffer[--i] = extra_c;
			return (write(1, &buffer[3], x - 3) + write(1, &buffer[i], length));
		}
		else if (!(flags & TIRET) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], x - padd_start) +
				write(1, &buffer[i], length - (1 - padd_start) - 2));
		}
	}
	buffer[--i] = 'x';
	buffer[--i] = '0';
	if (extra_c)
		buffer[--i] = extra_c;
	return (write(1, &buffer[i], BUFFER_SIZE - i - 1));
}
