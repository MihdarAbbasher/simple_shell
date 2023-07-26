#include "header.h"

/**
 * contain_char - contain_char ?
 * @str: key
 * @c: value
 * Return: 1 if str contains c char, 0 if not.
 */

int contain_char(char *str, char c)
{
    int i;

    while (str[i]){
        if (str[i] == c){
            return (1);
        }
        i++;
    }
    return (0);
}
