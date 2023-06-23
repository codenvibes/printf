/*
 * File: handle_conversion.c
 * Decsription: The source file associated with handle_conversion.h containing function
 *	        definitions.
 * Auth: Terrence M.K
 *	 Tamara Lumumba
 */

#include <stdarg.h>
#include "handle_conversion.h"
#include "print_utils.h"
/**
 * handle_conversion_specifier - Handles the conversion specifier.
 * @specifier: Conversion specifier character.
 * @args: va_list arguments.
 * @count: Pointer to the count of characters printed.
 *
 * Return: Always returns 0.
 */
int handle_conversion_specifier(const char specifier, va_list args, int *count)
{
	switch (specifier)
	{
		case 'c':
			print_char((char)va_arg(args, int), count);
			break;
		case 's':
			print_string(va_arg(args, char *), count);
			break;
		case 'd':
		case 'i':
			print_integer(va_arg(args, int), count);
			break;
		case '%':
			print_percentage(count);
			break;
		default:
			print_char('%', count);
			print_char(specifier, count);
			break;
	}

	return (0);
}
