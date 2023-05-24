#include "stander_header.h"

/**
 * check_builtin - check for built in function
 * @arguments: the arguments of command line
 * Return: 0 if it not an builtin function
 *
*/

int check_builtin(char **arguments)
{
	char *builtin[] = {"exit", "help", "cd"};
	int n = 0, i;
	char *str;

	if (arguments == NULL)
		return (-1);
	str = arguments[0];
	for (i = 0; i < 3; i++)
	{
		if (strcmp(builtin[i], str) == 0)
		{
			break;
		}
		n++;
	}
	n++;
	switch (n)
	{
	case 1:
		/* exit */
		write(STDOUT_FILENO, "this is exit function\n", 23);
		return (1);
	case 2:
		/* help */
		write(STDOUT_FILENO, "Welcome to my version of help\n", 30);
		return (2);
	case 3:
		/* cd */
		write(STDOUT_FILENO, "this is cd function\n", 20);
		return (3);
	default:
		return (0);
	}
}
