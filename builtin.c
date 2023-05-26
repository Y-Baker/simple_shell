#include "stander_header.h"


/**
 * checks - checks for builtin functions
 * @arguments: the arguments
 * @buffer: the buffer
 * @envr: the environment
 * Return: 0 if not builtin
*/

int checks(char **arguments, char *buffer, char **envr)
{
	int re_1, re_2;

	re_1 = check_builtin(arguments, buffer, envr);
	if (re_1 == 0)
	{
		re_2 = execute_builtin_command(arguments);
		if (re_2 == 0)
			return (0);
		else
			return (re_2);

	}
	return (re_1);
}


/**
 * check_builtin - check for built in function
 * @arguments: the arguments of command line
 * @buffer: the buffer
 * @envr: the environment
 * Return: 0 if it not an builtin function
 *
*/

int check_builtin(char **arguments, char *buffer, char **envr)
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
		own_exit(buffer, arguments);
		return (1);
	case 2:
		/* help */
		write(STDOUT_FILENO, "Welcome to my version of help\n", 30);
		return (2);
	case 3:
		own_cd(arguments, envr);
		return (3);
	default:
		return (0);
	}
}


/**
 * execute_builtin_command - execute a built-in shell command
 *
 * @args: the arguments for the command
 *
 * Return: 0 on success, -1 on failure
 */
int execute_builtin_command(char **args)
{
	if (strcmp(args[0], "setenv") == 0)
	{
		set_shell_env(args[1], args[2]);
		return (4);
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		unset_shell_env(args[1]);
		return (5);
	}

	return (0);
}
