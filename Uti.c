#include "main.h"

/**
 * _isprintable - Evaluate if a char is printable
 * @c: char
 * Return: 1 if true, 0 if false
*/
int _isprintable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code
 * @buffer: array
 * @i: int
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
*_isdigit - print only nbr
*@c: char
*Return: digit
*/
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (-1);
	return (0);
}

/**
*convert_size_nbr - fct to convert to nbr
*@num: long int
*@size: int
*Return: Num
*/
long int convert_size_nbr(long int num, int size)
{
if (size == MAJ)
	return (num);
else if (size == MIN)
	return ((short)num);
return ((int)num);
}

/**
*convert_size_unsgnd - fct to convert to nbr
*@num: unsigned long int
*@size: int
*Return: Num
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == MAJ)
	return (num);
else if (size == MIN)
	return ((unsigned short)num);
return ((unsigned int)num);
}
