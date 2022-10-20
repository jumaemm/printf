#include "main.h"

/**
 * print_id - print an integer/ base 10 argument
 * @ar_list: list of integer/decimal args
 * Return: count of printed args
 */
int print_id(va_list ar_list)
{
	int count, tens_exp, nums, digits;
	/*printf("I am in the decimal checker\n");*/
	/*We'll get the input and seperate the digits so that we print one by one*/
	nums = va_arg(ar_list, int);
	count = 0;
	/*printf("Nums is: %d", nums);*/
	/*for negative numbers, include a '-' symbol first*/
	if (nums < 0)
	{
		count += _putchar(45);/*45 is ASCII code for '-' */
		nums *= (-1);
	}
	/*get the number by 10 to exponent tens_exp i.e. (x * tens_exp)*/
	tens_exp = 1;
	digits = nums;

	while (digits > 9)
	{
		digits /= 10;
		tens_exp *= 10;
	}

	while (tens_exp >= 1)
	{
		count += _putchar(((nums / tens_exp) % 10) + 48);
		/*printf("count is %d", count);*/
		tens_exp /= 10;
	}
	return (count);
}
