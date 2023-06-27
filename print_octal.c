#include "print_utils.h"

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
