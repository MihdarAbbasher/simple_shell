#include "header.h"

/**
 * join_str - join_str1_to_str2
 * @str1: str1
 * @str2: str2
 * @c: char between the two str
 * Return: str.
 */

char *join_str(char *str1, char *str2, char c)
{
	char *str;
	int i, j, len;

	len = _strlen(str1) + _strlen(str2) + 2;
	printf("joined len: %d, str1: %s, str2: %s\n", len, str1, str2);
	str = malloc(sizeof(char) * len);
	printf("joined ptr: %p\n", str);
	if (!str)
	{
		_puts("malloc failed");
		return (NULL);
	}
	i = 0;
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = c;
	i++;
	j = 0;
	while (str2[j])
	{
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
	printf("joined str: %s\n", str);
	return (str);
}
