/*
 * File: handle_conversion.h
 * Decsription: a header file responsible for declaring the function that handles the
 *	        conversion specifier in the format string.
 * Auth: Terrence M.K
 *	 Tamara Lumumba
 */

#ifndef HANDLE_CONVERSIONS_H
#define HANDLE_CONVERSIONS_H

#include <stdarg.h>

/**
 * handle_conversion_specifier - Handles the conversion specifier.
 * @specifier: Conversion specifier character.
 * @args: va_list arguments.
 * @count: Pointer to the count of characters printed.
 *
 * Return: Always returns 0.
 */
int handle_conversion_specifier(const char specifier, va_list args, int *count);

#endif
