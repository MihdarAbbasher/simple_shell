#include "header.h"

/**
 * split_str - split str
 * @str: string
 * @delim: delimitor
 * Return: Always **char.
 */

char **split_str(char *str, const char *delim)
{
	char **arr, *str_token;
	int i;

	arr = malloc(10 * sizeof(char *));
	if (arr == NULL)
		_puts("allocation error\n"),
		exit(1);
	str_token = strtok(str, delim);
	i = 0;
	while (str_token != NULL)
	{
		arr[i] = str_token;
		str_token = strtok(NULL, delim);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
