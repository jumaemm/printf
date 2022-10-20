#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdarg.h>

/**
 * struct op - flag/function object
 * @key: char repping function
 * @value: function to be executed
 */
typedef struct op
{
	char *key;
	int (*value)(va_list);
} op_t;

int _putchar(char c);
int print_id(va_list ar_list);
int _printf(const char *format, ...);


#endif
