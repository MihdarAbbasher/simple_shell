#include "header.h"

/**
 * _getenv - _getenv
 * @key: key
 * Return: value.
 */

char *_getenv(char *key)
{
    char *current_str, *current_key;
    int i, len;

    len = strlen(key);
    i = 0;
    current_key = (char *) malloc((len + 1) * sizeof(char));
    if (!current_key){
        printf("malloc failed\n");
        return (NULL);
    }
    while(environ[i])
    {
        current_str = environ[i];
        strncpy(current_key, current_str, len + 1);
        if (current_key[len] == '='){
            current_key[len] = '\0';
            if (strcmp(key, current_key) == 0){
                free(current_key);
                return (&*(current_str + len + 1));
            }
        }
        
        i++;
    }
    free(current_key);
    return (NULL);
}
