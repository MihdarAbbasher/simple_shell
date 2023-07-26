#include "header.h"

/**
 * _unsetenv - _unsetenv
 * @key: key
 * Return: Always 0.
 */

int _unsetenv(char *key)
{
	char *res;
    char *current_str, *current_key;
    int i, len;

	res = _getenv(key);
	if (res){
	    printf("res: %s\n", res);
        if (!key || strlen(key) == 0){
        return (0);
        }
        len = strlen(key);
        printf("len: %d\n", len);

        i = 0;
        current_key = (char *) malloc((len + 1) * sizeof(char));
        if (!current_key){
            printf("malloc failed\n");
            return (-1);
        }
        while(environ[i])
        {
            current_str = environ[i];
            strncpy(current_key, current_str, len + 1);
            if (current_key[len] == '='){
                current_key[len] = '\0';
                if (strcmp(key, current_key) == 0){
                    printf("done\n");
                    free(current_key);
                    while (environ[i]){

                        environ[i] = environ[i + 1];
                        printf("moving %i: %s\n", i, environ[i]);
                        i++;
                    }
                    return (0);
                }
            }
            
            i++;
        }
        free(current_key);
	}

	return(0);
}
