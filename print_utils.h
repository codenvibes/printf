/*
 * File: print_utils.h
 * Decsription: This header file contains utility functions related to printing characters, strings,
 *	        and numbers. The functions in this file are responsible for the low-level printing
 *	        operations.
 * Auth: Terrence M.K
 *	 Tamara Lumumba
 */

#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H
#include <stddef.h>

/**
 * print_char - helper function to print a single character.
 * @c: character to be printed.
 * @count: pointer to the no. of characters printed.
 */
void print_char(char c, int *count);

/**
 * print_string - helper function to print strings.
 * @str: string to be printed.
 * @count: pointer to the no. of characters printed.
 */
void print_string(const char *str, int *count);

/**
 * print_decimal - Prints a decimal number.
 * @num: Decimal number to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_decimal(int num, int *count);

/**
 * print_integer - Prints an integer number.
 * @num: Integer number to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_integer(int num, int *count);

/**
 * print_percentage - Prints the percentage symbol.
 * @count: Pointer to the count of characters printed.
 */
void print_percentage(int *count);

/**
 * print_binary - Prints an unsigned integer in binary format.
 * @num: Unsigned integer to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_binary(unsigned int num, int *count);

/**
 * print_unsigned - Prints an unsigned integer number.
 * @num: Unsigned integer number to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_unsigned(unsigned int num, int *count);

/**
 * print_hex - Prints a hexadecimal number.
 * @num: Hexadecimal number to be printed.
 * @uppercase: Flag indicating if uppercase letters should be used (1) or not (0).
 * @count: Pointer to the count of characters printed.
 */
void print_hex(unsigned int num, int uppercase, int *count);

/**
 * print_octal - Prints an octal number.
 * @num: Octal number to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_octal(unsigned int num, int *count);

/**
 * print_non_printable - Prints a non-printable character in the format \x followed by the ASCII code value in hexadecimal.
 * @c: Character to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_non_printable(char c, int *count);

/**
 * print_non_printable_string - Prints a string with non-printable characters in the format \x followed by the ASCII code value in hexadecimal.
 * @str: String to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_non_printable_string(const char *str, int *count);

/**
 * print_address - Prints a memory address.
 * @address: Address to be printed.
 * @count: Pointer to the count of characters printed.
 */
void print_address(void *address, int *count);


#endif
