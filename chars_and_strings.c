#include "main.h"

/**
 * print_s - print string and return count
 * @ar_list: string args
 * Return: count of printed args
 */
int print_s(va_list ar_list)
{

	char *str;
	int itr;

	str =  va_arg(ar_list, char *);
	if (str == NULL)
		str = "(null)";
	for (itr = 0; str[itr] != '\0'; itr++)
		_putchar(str[itr]);
	return (itr);
}

/**
 * print_c - Print character
 * @ar_list: char argument
 * Return: count of printed args
 */
int print_c(va_list ar_list)
{
	_putchar(va_arg(ar_list, int));
	return (1);
}

