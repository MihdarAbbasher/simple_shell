#include "header.h"

/**
 * _setenv - _setenv
 * @key: key
 * @value: value
 * @overwrite: arr of str
 * Return: Always 0.
 */

int _setenv(char *name, char *value, int overwrite)
{
	char *res;
    int i;

	res = _getenv(name);
	if (res){
		if (overwrite){
			strcpy(res, value);
			res = value;

		}
	}
	else{
		printf("add\n");
        res = join_str(name, value, '=');
        i = 0;
        while (environ[i]){
            i++;
        }
        environ[i] = res;
        environ[i + 1] = NULL;
	}
	return(0);

}
