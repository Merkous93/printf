#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024
int _printf(const char *format, ...);
#define TIRET 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16
int handle_flags(const char *format, int *i);
int handle_length(const char *format, int *i);
int handle_precision(const char *format, int *i, va_list list);
int handle_print(const char *format, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int len);
int _isdigit(char c);
int handle_width(const char *format, int *i, va_list list);
#define MIN 1
#define MAJ 2
/**
 *struct format - struct op
 *@format: char
 *@fn: int
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};
typedef struct format format_t;
long int convert_size_nbr(long int num, int len);
long int convert_size_unsgnd(unsigned long int num, int len);
int handle_len(const char *format, int *i);
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int len);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_pourcentage(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_unsgnd(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int len);
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int len);
int handle_char(char c, char buffer[],
	int flags, int width, int precision, int len);
int write_number(int is_positive, int i, char buffer[],
	int flags, int width, int precision, int len);
int write_num(int i, char buffer[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int i, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int i, char buffer[],
	int flags, int width, int precision, int len);
int _isprintable(char);
int append_hexa_code(char, char[], int);
#endif
