#include "header.h"
/**
 * execute_builtin_cmd - Executes a built-in command
 * @cmd_arr: tokens arr
 * @line: ...
 * Return: 1 if is a built-in command or 0 if not
 */
int execute_builtin_cmd(char **cmd_arr, char *line)
{
	int i = 0;
	char *ListBuiltinCmds[] = { "exit", "cd", "help", "env", NULL };

	while (ListBuiltinCmds[i])
	{
		if (_strcmp(cmd_arr[0], ListBuiltinCmds[i]) == 0)
		{
			switch (i)
			{
				case 0:
					run_exit(cmd_arr, line);
					return (0);
				case 1:
					chdir(cmd_arr[1]);
					return (1);
				case 2:
					_open_help();
					return (1);
				case 3:
					_print_env();
					return (1);
				default:
					break;
			}
		}
		i++;
	}

	return (0);
}

