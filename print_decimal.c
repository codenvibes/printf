#include "print_utils.h"

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
