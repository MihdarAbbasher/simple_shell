#include "header.h"

/**
 * run_cd - find dir_name
 * @dir_name: dir.
 * Return: 0 if not found, 1 if found.
 */

void run_cd(char *dir_name)
{
	char new_dir[PATH_MAX];

	if (chdir(dir_name) != 0)
	{
		printf("%s: not found\n", dir_name);
	}
	else
	{
		if (getcwd(new_dir, sizeof(new_dir)) != NULL)
		{
			_setenv("PWD", new_dir, 1);
		}
		else
		{
			_puts("getcwd error\n");
		}
	}
}
