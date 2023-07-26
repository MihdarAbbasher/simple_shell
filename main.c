#include "header.h"

/**
 * main - simple shell
 * Write a program that executes the command
 * Return: Always 0.
 */

int main(void)
{
    pid_t child_pid, curr_pid;
    int status, execute_value;
    char *str, **cmd_arr, *delim, *cmd;
	
    
    delim = " \n";
    while (1){
        str = get_command();
        cmd_arr = split_str(str, delim);
        print_arr(cmd_arr);

        /* check for cd and exit */
        if (strcmp(cmd_arr[0], "cd") == 0){
            if (cmd_arr[0] && cmd_arr[1] && !cmd_arr[2])
                run_cd(cmd_arr[1]);
            else{
                printf("usage: cd <dir>\n");
            }
            continue;
        }
        if (strcmp(cmd_arr[0], "exit") == 0){
            free(str);
            free(cmd_arr);
            run_exit();
        }
        
        /* search for cmd_arr[0] in PATH dir */
        cmd = find_file(cmd_arr[0]);
        if (!cmd){
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
                /* only executed if error occur;
                end the newly created process 
                execute_value = execute_cmd(NULL);*/
                return (1);
        }
        else
        {
            wait(&status);
        }
    }
    if (curr_pid == 0){
        printf("curr pid = 0, cmd: %s\n", cmd);
    }
    if (cmd)
        free(cmd);
    return (0);
}
