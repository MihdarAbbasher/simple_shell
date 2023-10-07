#include "header.h"

/**
 * contain_char - contain_char ?
 * @str: key
 * @c: value
 * Return: 1 if str contains c char, 0 if not.
 */

void free_cmd(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		printf("str[%d]: %s\n", i, str[i]);
		free(str[i]);
		i++;
	}
}
