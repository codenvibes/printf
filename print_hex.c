#include "print_utils.h"

/**
 * print_hex - Prints a hexadecimal number.
 * @num: Hexadecimal number to be printed.
 * @is_uppercase: Flag indicating if letters should be printed in uppercase.
 * @count: Pointer to the count of characters printed.
 * @print_prefix: Flag indicating if the '#' prefix should be printed.
 */
void print_hex(unsigned int num, bool is_uppercase, int *count, bool
		 print_prefix)
{
	char digits[] = "0123456789abcdef";
	int base = 16;

	if (print_prefix)
	{
		print_char('0', count);
		print_char(is_uppercase ? 'X' : 'x', count);
	}

	if (num / base)
		print_hex(num / base, is_uppercase, count, false);

	print_char(digits[num % base], count);
}
