/*
 * File: _printf.c
 * Decsription: Recreating the printf function of the C standard library.
 * Auth: Terrence M.K
 *	 Tamara Lumumba
 */

#include "main.h"
#include "handle_conversion.h"
#include "print_utils.h"
#include <unistd.h> /* access the declaration of write function */
/* access to macros & types that handle variable arguments */
#include <stdarg.h>

/**
 * _printf - a function that prints output according to a format.
 * @format: the format string.
 *
 * Return: the no. of string characters.
 */
int _printf(const char *format, ...)
{
	va_list args; /* Create a va_list to hold the variable arguments */
	int count = 0; /* a variable to keep track of the no. of characters printed */

	/* Start the variable argument list */
	va_start(args, format);

	while (format && *format)
	{
		if (*format != '%')
		{
			print_char(*format, &count);
		}
		else
		{
			format++;
			handle_conversion_specifier(*format, args, &count);
		}

		format++;
	}

	/* End the variable argument list */
	va_end(args);

	return (count);
}


