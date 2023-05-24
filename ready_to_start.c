#include "stander_header.h"

/**
 * ready - to start shell
 *
 * Parameter:
 * @argv: the argv
 * @envr: the evironment
*/

void ready(char *argv[], char **envr)
{
	ssize_t ret;
	char *buffer = NULL, **arguments;
	size_t size = 0;
	int builtin_return;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		ret = getline(&buffer, &size, stdin);
		if (ret == -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		arguments = _strtok(buffer, ret);
		builtin_return = check_builtin(arguments);
		if (builtin_return == 0)
			run_fork(arguments, argv[0], envr);
		free(arguments);
		free(buffer);
		buffer = NULL;
	}
}
