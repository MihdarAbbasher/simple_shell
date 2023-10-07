#include "header.h"

/**
 * main - simple shell
 * Return: Always 0.
 */

int main(void)
{
	char *str, *delim, **cmd_arr;
	pid_t child_pid;
	int status;

	delim = " \t\n";
	while (1)
	{
		str = get_command();
		cmd_arr = split_str(str, delim);
		if (is_exist(str))
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				return (1);
			}
			if (child_pid == 0)
			{
				if (execute_cmd(str, cmd_arr) == -1)
					return (1);
			}
			else
				wait(&status);
		}
		else
			printf("%s: command not found\n", str);
	}
		
	return (0);
}
