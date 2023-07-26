#include "header.h"

/**
 * execute_cmd - execute cmd
 * @argv: args vector
 * @cmd: cmd
 * Return: 0 if not found, -1 if found.
 */

int execute_cmd(char *cmd, char *argv[])
{
	if (execve(cmd, argv, environ) == -1)
		perror("Error");
	return (-1);
}

