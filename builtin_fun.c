#include "stander_header.h"

/**
 * own_exit - the exit function
 * @buffer: the buffer
 * @arguments: the arguments array
*/

void own_exit(char *buffer, char **arguments)
{
	free(arguments);
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
 * own_cd - the cd commamd
 * @args: the arguments array
 * @envr: the environment
*/
void own_cd(char **args, char **envr)
{
	int re;
	char *dir, *pwd, buffer[1024];

	pwd = getcwd(buffer, 1024);
	if (!pwd)
		dprintf(STDERR_FILENO, "getcwd failure!\n");
	if (args[1] == NULL)
	{
		dir = get_envr_variable(envr, "HOME");
		if (dir == NULL)
			re = chdir((dir = get_envr_variable(envr, "PWD")) ? dir : "/");
		else
			re = chdir(dir);
	}
	else if (strcmp(args[1], "-") == 0)
	{
		if (!get_envr_variable(envr, "OLDPWD"))
		{
			dprintf(STDOUT_FILENO, "%s\n", pwd);
			return;
		}
		dprintf(STDOUT_FILENO, "%s\n", get_envr_variable(envr, "OLDPWD"));
		re = chdir((dir = get_envr_variable(envr, "OLDPWD")) ? dir : "/");
	}
	else
		re = chdir(args[1]);

	if (re != 0)
		dprintf(STDERR_FILENO, "can't go to %s\n", args[1]);
	else
	{
		setenv("OLDPWD", get_envr_variable(envr, "PWD"), 1);
		setenv("PWD", getcwd(buffer, 1024), 1);
	}
}
