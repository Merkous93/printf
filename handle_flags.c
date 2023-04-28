#include "main.h"
/**
*handle_flags - handle the active flags
*@format: char
*@i: int
*Return: Flags
*/
int handle_flags(const char *format, int *i)
{
int x, y, flags;
const char symbols[] = {'-', '+', ' ', '#', '0', '\0'};
const int array[] = {TIRET, PLUS, SPACE, HASH, ZERO, 0};
flags = 0;
	for (x = *i + 1; format[x] != '\0'; x++)
	{
		for (y = 0; symbols[y] != '\0'; y++)
			if (format[x] == symbols[y])
			{
				flags |= array[y];
				break;
			}
		if (symbols[y] == 0)
			break;
	}
	*i = x - 1;
	return (flags);
}
