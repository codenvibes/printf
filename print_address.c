#include <stdint.h>
#include "print_utils.h"

/**
 * print_address - Prints a memory address.
 * @address: Address to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_address(void *address, int *count)
{
	uintptr_t addr = (uintptr_t)address;
	int leading_zeroes = sizeof(void *) * 2 - 1;
	int i;

	print_char('0', count);
	print_char('x', count);

	for (i = leading_zeroes; i >= 0; i--)
	{
		int digit = (addr >> (i * 4)) & 0xF;

		if (digit != 0 || i == 0)
		{
			if (digit < 10)
				print_char('0' + digit, count);
			else
				print_char('a' + (digit - 10), count);
		}
	}
}
