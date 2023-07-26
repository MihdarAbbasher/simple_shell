#include "header.h"

/**
 * is_exist - find file
 * @fullname: filename.
 * Return: 0 if not found, 1 if found.
 */

int is_exist(char *fullname)
{
    struct stat st;

    if (stat(fullname, &st) == 0)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
