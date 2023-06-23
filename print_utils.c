/*
 * File: _printf.c
 * Decsription: The corresponding source file for print_utils.h contains the
 *	        implementations of the printing utility functions.
 * Auth: Terrence M.K
 *	 Tamara Lumumba
 */

#include <unistd.h>
#include "print_utils.h"

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
