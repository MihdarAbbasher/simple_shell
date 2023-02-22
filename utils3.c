#include "shell.h"

/**
  * remove_new_line - Removes a new line character from string
  * @str: The string
  *
  * Return: The string without a new line character
  */
char *remove_new_line(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}

	return (str);
}


/**
  * signal_handler - handle terminal signal
  * @sig: The signal
  *
  * Return: nothing
  */

void signal_handler(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

