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
	va_list args; /* variable argument list */
	int count = 0; /* no. of characters printed */
	int flags = 0;

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
			flags = 0;

			/* Handle flags */
			while (*format == '+' || *format == ' ' || *format == '#')
			{
				switch (*format)
				{
					case '+':
						flags |= 1;
						break;
					case ' ':
						flags |= 2;
						break;
					case '#':
						flags |= 4;
						break;
				}
				format++;
			}

			handle_conversion_specifier(*format, args, &count);
		}

		format++;
	}

	va_end(args);

	return (count);
}

