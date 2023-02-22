#include <stdio.h>
#include "shell.h"

void signal_handler(int sig);
/**
  * main - Entry point to the Shell
  *
  * Return: Always zero.
  */
int main()
{
	char *line = NULL, **tokens = NULL;
	int words_no = 0, execFlag = 0;
	size_t line_size = 0;
	ssize_t line_len = 0;

	while (line_len >= 0)
	{
		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		line_len = getline(&line, &line_size, stdin);
		if (line_len == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		words_no = count_words(line);
		if (words_no > 0)
		{
			tokens = split_words(line, " \t", words_no);
			execFlag = execBuiltInCommands(tokens, line);
			if (!execFlag)
			{
				tokens[0] = find(tokens[0]);
				if (tokens[0] && access(tokens[0], X_OK) == 0)
					exec(tokens[0], tokens);
				else
					perror("./hsh");
			}

		}
		
	}
	return (0);
}

/**
  * count_words - Counts the words typed by the user
  * @str: The string that contains the words
  *
  * Return: The number of words found in the string
  */
int count_words(char *str)
{
	int i = 0, cw = 0, state = 0;

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			cw++;
		}

		i++;
	}

	return (cw);
}

/**
  * count_delims - Counts delimiters in a string
  * @str: The string that contains the delimiters
  * @del: The delimiters to will find in the string
  *
  * Return: The number of delimiters in the string
  */
int count_delims(char *str, char *del)
{
	int i = 0, j = 0, cw = 0;

	while (del[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == del[i])
				cw++;
			j++;
		}
		i++;
	}

	return (cw);
}


/**
  * split_words - Extract tokens from string
  * @str: The string to tokenize
  * @del: The delimiter of tokenization
  * @len: Tokens number
  *
  * Return: An array of tokens of the string
  */
char **split_words(char *str, char *del, int len)
{
	char **tokens = NULL, *token = NULL, *temp = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * (len + 1));
	if (!tokens)
		return (NULL);

	str = remove_new_line(str);
	temp = _strdup(str);
	token = strtok(temp, del);

	while (token)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, del);
		i++;
	}

	tokens[i] = NULL;
	free(temp);
	return (tokens);
}
