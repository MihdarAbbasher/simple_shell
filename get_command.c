#include "header.h"

/**
 * get_command - get line cmd
 *
 */

char *get_command()
{
	size_t size;
	int act_size;
	char *linestr;

	/* printf("%s", _getenv("PWD")); // print cwd */
	putchar('$');
	putchar(' ');
	size = 32;
	act_size = 0;
	linestr = (char *) malloc(size * sizeof(char));
	if(linestr == NULL)
		printf("unable to allocate memory\n"),
		exit(1);
	act_size = getline(&linestr, &size, stdin);
	if (act_size == -1)
		exit(1);
	return (linestr);
}
