#include "header.h"

/**
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/

/**
 * join_str1_to_str2 - join_str1_to_str2
 * @str1: str1
 * @str2: str2
 * @c: char between the two str
 * Return: str.
 */

char *join_str(char *str1, char *str2, char c)
{
    char *str;
	int len, i, j;

    len = strlen(str1) + strlen(str2) + 2;
	str = malloc(len * sizeof(char));
	if (!str){
		printf("malloc failed");
		return(NULL);
	}
	i = 0;
	while (str1[i]){
		str[i] = str1[i];
		i++;
	}
	str[i] = c;
	i++;
	j = 0;
	while (str2[j]){
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
    return(str);

}
