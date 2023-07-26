#include "header.h"

/**
 * print_env - prints the environment
 * using the global variable environ
 *
 * Return: Always 0.
 */


void print_env()
{
    unsigned int i;

    i = 0;
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}
