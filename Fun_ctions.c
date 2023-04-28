#include "main.h"

/**
 * print_unsgnd - Print an unsgnd nbr
  * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_unsgnd(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, len);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, len));
}
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, len);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & HASH && init_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, len));
}

/**
 * print_hexadecimal - Prints an unsigned nbr in hexadecimal notation
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, len));
}

/**
 * print_hexa_upper - Print an unsigned nbr in upper hexadecimal
 * @types: arg
 * @buffer: array
 * @flags:  int
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int len)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, len));
}

/**
 * print_hexa - Print a hexadecimal nbr in lower or upper
 * @types: arg
 *@map_to : arg
 * @buffer: array
 * @flags:  int
 *@flag_ch: char
 * @width: int
 * @precision: int
 * @len: int
 * Return: Nbr of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int len)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, len);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, len));
}
