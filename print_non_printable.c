#include "print_utils.h"

/**
 * print_non_printable - Prints a non-printable character in the format \x
 *	followed by the ASCII code value in hexadecimal.
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
