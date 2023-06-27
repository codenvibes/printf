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

