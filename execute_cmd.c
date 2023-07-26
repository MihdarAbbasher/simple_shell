#include "header.h"

/**
 * execute_cmd - execute cmd
 * @argv: args vector
 */

int execute_cmd(char *cmd, char *argv[])
{
    if (execve(cmd, argv, environ) == -1)
    {
        perror("Error");
    }
    return (-1);
}

