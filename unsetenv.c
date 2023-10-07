#include "header.h"
/**
 * _unsetenv - _unsetenv
 * @key: key
 * Return: Always 0.
 */

int _unsetenv(char *key)
{
	char *res;
	char *current_str, *current_key;
	int i, len;

	res = _getenv(key);
	if (res)
	{
		if (!key || _strlen(key) == 0)
			return (0);
		len = _strlen(key);
		i = 0;
		current_key = (char *) malloc((len + 1) * sizeof(char));
		if (!current_key)
		{
			_puts("allocation error\n");
			return (-1);
		}
		while (environ[i])
		{
			current_str = environ[i];
			strncpy(current_key, current_str, len + 1);
			if (current_key[len] == '=')
			{
				current_key[len] = '\0';
				if (strcmp(key, current_key) == 0)
				{
					free(current_key);
					while (environ[i])
					{

						environ[i] = environ[i + 1];
						i++;
					}
					return (0);
				}
			}
			i++;
		}
		free(current_key);
	}

	return (0);
}
