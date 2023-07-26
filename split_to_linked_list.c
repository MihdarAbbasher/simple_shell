#include "header.h"

/**
 * split_to_linked_list - split str
 * @str: string
 * @delim: delimitor
 */

list_t *split_to_linked_list(char *str, const char *delim)
{
	char *str_token;
	int i;
    list_t *mylist;

	mylist =  NULL;
    str_token = strtok(str, delim);
	i = 0;
	while (str_token != NULL)
	{
		add_node_end(&mylist, str_token);
		str_token = strtok(NULL, delim);
		i++;
	}
	return (mylist);
}


