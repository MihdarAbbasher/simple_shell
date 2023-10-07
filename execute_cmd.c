#include "header.h"

/**
 * execute_cmd - execute cmd
 * @argv: args vector
 * @cmd: cmd
 * Return: -1 if cmd not found.
 */

int execute_cmd(char *cmd, char *argv[])
{
	if (execve(cmd, argv, environ) == -1)
	{
		perror("Error");
		return (-1);
	}
	return (0);
}

