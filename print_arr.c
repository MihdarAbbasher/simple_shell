#include "header.h"

/**
 * print_arr - prints the environment
 * using the global variable environ
 * @arr: value
 * Return: Always 0.
 */


void print_arr(char **arr)
{
	unsigned int i;

	i = 0;
	while (arr[i] != NULL)
	{
		_puts(arr[i]);
		_putchar('\n');
		i++;
	}
}
