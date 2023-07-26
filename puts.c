#include "header.h"
/**
 * _puts - check the co
 * @s: char pointer
 * Return: int len
*/
void _puts(char *s)
{
	int i = 0;
	char c;

	while (1 == 1)
	{
		c = *(s + i);
		if (c != '\0')
		{
			_putchar(c);
			i += 1;
		}
		else
		{
			break;
		}
	}
}
