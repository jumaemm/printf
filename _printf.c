#include "main.h"

/**
 * func_checker - get right function for printing args
 * @c: char to check
 * Return: pointer to print function
 */
int (*func_checker(char c))(va_list)
{
	op_t funcs[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_id},
		{"d", print_id},
		{NULL, NULL}
	};
	int i;

	/*printf("I am in the func checker\n");*/
	for (i = 0; funcs[i].key != NULL; i++)
	{
		if (*funcs[i].key == c)
		{
			/*printf("I should return a value\n");*/
			return (funcs[i].value);
		}
	}
	return (0);
}
/**
 * _printf - print args to stdout
 * @format: character string of zero or more directives
 * Return: count of printed args
 */
int _printf(const char *format, ...)
{
	/*if format is NULL count is -1*/
	int cn = -1;

	if (format != NULL)
	{
		int i;
		va_list ar_list;
		int (*printer)(va_list);
		char *fm = "\n";

		va_start(ar_list, format);

		cn = 0;
		for (i = 0; format[i] != '\0'; i++)
		{
			/*check for % flag*/
			if (format[i] == '%')
			{
				/*check if next char is also %*/
				if (format[i + 1] == '%')
				{
					cn += _putchar(format[i]);
					i++;
				}
				else if (format[i + 1] != '\0')
				{
					printer = func_checker(format[i + 1]);
					fm = format[i + 1];
					cn += (printer ? printer(ar_list) : _putchar(format[i]) + _putchar(fm));
					i++;
				}
			}
			else
				cn += _putchar(format[i]);
		}
		va_end(ar_list);
	}
	return (cn);
}
