/*
 * File: _printf.c
 * Decsription: Recreating the printf function of the C standard library.
 * Auth: Terrence M.K
 *	 Tamara Lumumba
 */

#include "main.h"
#include <unistd.h> /* access the declaration of write function */
/* access to macros & types that handle variable arguments */
#include <stdarg.h>

/**
 * print_char - helper function to print a single character.
 * @c: character to be printed.
 * @count: pointer to the no. of characters printed.
 */
void print_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

/**
 * print_string - helper function to print strings.
 * @str: string to be printed.
 * @count: pointer to the no. of characters printed.
 */
void print_string(const char *str, int *count)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
		(*count)++;
	}
}

/**
 * print_decimal - Prints a decimal number.
 * @num: Decimal number to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_decimal(int num, int *count)
{
	if (num < 0)
	{
		print_char('-', count);
		num = -num;
	}

	if (num / 10)
		print_decimal(num / 10, count);

	print_char('0' + (num % 10), count);
}

/**
 * print_integer - Prints an integer number.
 * @num: Integer number to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_integer(int num, int *count)
{
	print_decimal(num, count);
}

/**
 * print_percentage - Prints the percentage symbol.
 * @count: Pointer to the count of characters printed.
 */
void print_percentage(int *count)
{
	print_char('%', count);
}

/**
 * handle_conversion_specifier - Handles the conversion specifier.
 * @specifier: Conversion specifier character.
 * @args: va_list arguments.
 * @count: Pointer to the count of characters printed.
 *
 * Return: Always returns 0.
 */
int handle_conversion_specifier(const char specifier, va_list args, int *count)
{
	switch (specifier)
	{
		case 'c':
			print_char((char)va_arg(args, int), count);
			break;
		case 's':
			print_string(va_arg(args, char *), count);
			break;
		case 'd':
		case 'i':
			print_integer(va_arg(args, int), count);
			break;
		case '%':
			print_percentage(count);
			break;
		default:
			print_char('%', count);
			print_char(specifier, count);
			break;
	}

	return (0);
}

/**
 * _printf - a function that prints output according to a format.
 * @format: the format string.
 *
 * Return: the no. of string characters.
 */
int _printf(const char *format, ...)
{
	va_list args; /* variable argument list */
	int count = 0; /* no. of characters printed */

	va_start(args, format);

	while (format && *format)
	{
		if (*format != '%')
		{
			print_char(*format, &count);
		}
		else
		{
			format++;
			handle_conversion_specifier(*format, args, &count);
		}

		format++;
	}

	va_end(args);

	return (count);
}

