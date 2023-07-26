#ifndef HEADER_H
#define HEADER_H

extern char **environ;

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *join_str(char *str1, char *str2, char c);
char **split_str(char *str, const char *delim);
list_t *split_to_linked_list(char *str, const char *delim);
list_t *add_node_end(list_t **head, const char *str);
int contain_char(char *str, char c);
int execute_cmd(char *cmd, char *argv[]);
char *find_file(char *file);
char *get_command();
int is_exist(char *file);
void print_env();
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *key);
void run_cd(char *dir_name);
void run_exit();
void print_arr(char **arr);
char *_getenv(char *key);

#endif