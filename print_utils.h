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

#endif
