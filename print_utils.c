/*
 * File: print_utils.c
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

/**
 * print_binary - Prints an unsigned integer in binary format.
 * @num: Unsigned integer to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_binary(unsigned int num, int *count)
{
	if (num / 2)
		print_binary(num / 2, count);

	print_char('0' + (num % 2), count);
}

/**
 * print_unsigned - Prints an unsigned integer number.
 * @num: Unsigned integer number to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_unsigned(unsigned int num, int *count)
{
	if (num / 10)
		print_unsigned(num / 10, count);

	print_char('0' + (num % 10), count);
}

/**
 * print_hex - Prints a hexadecimal number.
 * @num: Hexadecimal number to be printed.
 * @uppercase: Flag indicating if uppercase letters should be used (1) or not (0).
 * @count: Pointer to the count of characters printed.
 */
void print_hex(unsigned int num, int uppercase, int *count)
{
	char *hex_digits_lower = "0123456789abcdef";
	char *hex_digits_upper = "0123456789ABCDEF";
	char *hex_digits = uppercase ? hex_digits_upper : hex_digits_lower;

	if (num / 16)
		print_hex(num / 16, uppercase, count);

	print_char(hex_digits[num % 16], count);
}

/**
 * print_octal - Prints an octal number.
 * @num: Octal number to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_octal(unsigned int num, int *count)
{
	if (num / 8)
		print_octal(num / 8, count);

	print_char('0' + (num % 8), count);
}

/**
 * print_non_printable - Prints a non-printable character in the format \x followed by the ASCII code value in hexadecimal.
 * @c: Character to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_non_printable(char c, int *count)
{
	char hex_digits[] = "0123456789ABCDEF";

	print_char('\\', count);
	print_char('x', count);
	print_char(hex_digits[(c >> 4) & 0xF], count);
	print_char(hex_digits[c & 0xF], count);
}

/**
 * print_non_printable_string - Prints a string with non-printable characters in the format \x followed by the ASCII code value in hexadecimal.
 * @str: String to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_non_printable_string(const char *str, int *count)
{
	while (*str)
	{
		if (*str >= ' ' && *str < 127)
			print_char(*str, count);
		else
			print_non_printable(*str, count);

		str++;
	}
}
