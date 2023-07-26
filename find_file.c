#include "header.h"

/**
 * find_file - find file
 * @file: filename.
 * @path: path.
 * Return: 0 if not found, 1 if found.
 */

char *find_file(char *file)
{
    char *PATH_val, **PATH_dir_arr, *fullname, *PATH_copy;
    int i;
    unsigned int len;
    
    PATH_val = _getenv("PATH");
    len = strlen(PATH_val);

    PATH_copy = malloc((len + 1)* sizeof(char));
    if (!PATH_copy){
        printf("malloc failed\n");
        return(NULL);
    }
    strcpy(PATH_copy, PATH_val);
    PATH_dir_arr = split_str(PATH_copy, ":");
    i = 0;
    while(PATH_dir_arr[i]){
        fullname = join_str(PATH_dir_arr[i], file, '/');
        if (is_exist(fullname)){
            free(PATH_copy);
            return (fullname);
        }
        i++;
    }
    return (NULL);
}
