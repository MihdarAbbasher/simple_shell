#include "header.h"

/**
 * main - simple shell
 * Return: Always 0.
 */

int main(void)
{
	pid_t child_pid, curr_pid;
	int status;
	char *str, **cmd_arr, *delim, *cmd;

	delim = " \t\n";
	while (1)
	{
		str = get_command();
		cmd_arr = split_str(str, delim);
		if (execute_builtin_cmd(cmd_arr))
			continue;
		cmd = find_file(cmd_arr[0]);
		if (!cmd)
		{
			_puts(cmd_arr[0]);
			_puts(": No such file or directory\n");
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		curr_pid = getpid();
		if (child_pid == 0)
		{
			if (execute_cmd(cmd, cmd_arr) == -1)
				return (1);
		}
		else
			wait(&status);
	}
	if (curr_pid == 0)
		_putchar('\n');
	if (cmd)
		free(cmd);
	return (0);
}
