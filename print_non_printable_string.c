#include "print_utils.h"

/**
 * print_non_printable_string - Prints a string with non-printable characters
 *	in the format \x followed by the ASCII code value in hexadecimal.
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
