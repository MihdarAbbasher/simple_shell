#include "header.h"

/**
 * run_exit - exit
 * @cmd_arr: cmd_arr.
 * @line: str.
 * Return: 0 if not found, 1 if found.
 */

void run_exit(char **cmd_arr, char *line)
{
	free_cmd(cmd_arr);
	free(line);
	exit(0);
}
