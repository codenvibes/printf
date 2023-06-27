#include "print_utils.h"

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
