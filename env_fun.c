#include "stander_header.h"

/**
 * set_shell_env - set the value of a shell environment variable
 *
 * @variable: the name of the environment variable
 * @value: the value to be set
 *
 * Return: 0 on success, -1 on failure
 */
int set_shell_env(const char *variable, const char *value)
{
	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "set_shell_env: Missing arguments\n");
		return (-1);
	}

	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}

/**
 * unset_shell_env - unset a shell environment variable
 *
 * @variable: the name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int unset_shell_env(const char *variable)
{
	if (variable == NULL)
	{
		fprintf(stderr, "unset_shell_env: Missing argument\n");
		return (-1);
	}

	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}
