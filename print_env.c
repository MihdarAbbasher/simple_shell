#include "header.h"

/**
 * print_env - prints the environment
 * using the global variable environ
 *
 * Return: Always 0.
 */


void print_env(void)
{
	print_arr(environ);
}
