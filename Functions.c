#include "main.h"
/**
 * print_char - Print a char
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	char c = va_arg(types, int);

	return (handle_char(c, buffer, flags, width, precision, len));
}

/**
 * print_string - Print a string
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
char *str;
int length, i;
length = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(len);
str = va_arg(types, char *);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}

	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & TIRET)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/**
 * print_percent - Print a pourcentage sign
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_pourcentage(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(len);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	int i = BUFFER_SIZE - 2;
	int _isnegative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_nbr(n, len);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		_isnegative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(_isnegative, i, buffer, flags, width, precision, len));
}

/**
 * print_binary - Print an unsigned number
  * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	unsigned int n, m, i, sum;
	unsigned int x[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(len);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	x[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		x[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += x[i];
		if (sum || i == 31)
		{
			char z = '0' + x[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
