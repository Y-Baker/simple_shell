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
	int stats;
	pid_t child_pid;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		ret = getline(&buffer, &size, stdin);
		if (ret == -1)
			exit(EXIT_FAILURE);
		arguments = _strtok(buffer, ret);

		child_pid = fork();
		if (child_pid == -1)
		{
			free(arguments);
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0 && arguments)
		{
			if (execve(arguments[0], arguments, envr) == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
			wait(&stats);

		free(arguments);
		free(buffer);
		buffer = NULL;
	}
}
