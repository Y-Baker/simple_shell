#include "stander_header.h"

/**
 * get_envr_variable - get the path from envp
 * @envp: the environment vector
 * @var: varaibal name
 * Return: the value of the variable
*/

char *get_envr_variable(char *envp[], char *var)
{
	int i;
	size_t var_len = strlen(var);

	for (i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], var, var_len) == 0 && envp[i][var_len] == '=')
			return (envp[i] + var_len + 1);
	}

	return (NULL);
}
