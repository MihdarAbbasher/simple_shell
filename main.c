#include "header.h"

/**
 * main - simple shell
 * Return: Always 0.
 */

int main(void)
{
	pid_t child_pid, curr_pid;
	int status, execute_value;
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
			printf("%s: No such file or directory\n", cmd_arr[0]);
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
			execute_value = execute_cmd(cmd, cmd_arr);
			if (execute_value == -1)
				return (1);
		}
		else
			wait(&status);
	}
	if (curr_pid == 0)
		printf("curr pid = 0, cmd: %s\n", cmd);
	if (cmd)
	free(cmd);
	return (0);
}
