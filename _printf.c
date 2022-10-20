#include "main.h"

/**
 * func_checker - get right function for printing args
 * c: char to check
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

	for (i = 0; funcs[i].key != NULL; i++)
	{
		if (funcs[i].key == c)
			return (funcs[i].value);
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
	int count = -1;

	if (format != NULL)
	{
		int i;
		va_list ap;
		int (*search)(ar_list);

		va_start(ar_list, format);

		count = 0;
		for (i = 0; format[i] != '\0'; i++)
		{
			/*check for % flag*/
			if (format[i] == '%')
			{
				/*check if next char is also %*/
				if (format[i + 1] == '%')
				{
					count += _putchar(format[i]);
				}
				else if (format[i + 1] != '\0')
				{
					printer = func_checker(format[i + 1]);
					if (printer != NULL)
					{
						count += printer(ar_list);
					}
					else
						count += (_putchar(format[i]) + _putchar(format[i + 1]));
				}

			}
			else
				count += _putchar(format[i]);
		}
		va_end(ar_list);
	}
	return (count);
}
