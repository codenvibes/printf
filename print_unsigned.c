#include "print_utils.h"

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
