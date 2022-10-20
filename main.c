#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len1 = 5;
    int len2 = 6;
    int len_negative = -10;

    _printf("Let's try to printf [%d] and [%i].\n", len1, len2);
    _printf("Let's try to print a negative:%d\n", len_negative);
    _printf("Printing my name [%s]\n", "Killian");
    _printf("My name starts with letter:%c\n", 'K');

    return (0);
}
