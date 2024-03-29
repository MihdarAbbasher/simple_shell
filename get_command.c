#include "header.h"

/**
 * get_command - get line cmd
 * Return: nothing
 */

char *get_command()
{
	size_t size;
	int act_size;
	char *linestr;

	/* printf("%s$ ", _getenv("PWD")); */
	write(STDOUT_FILENO, "($) ", 4);
	size = 32;
	act_size = 0;
	linestr = (char *) malloc(size * sizeof(char));
	if (linestr == NULL)
		_puts("unable to allocate memory\n"),
		exit(1);
	act_size = getline(&linestr, &size, stdin);
	if (act_size == -1)
		exit(1);
	return (linestr);
}
