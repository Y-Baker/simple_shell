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
	char *buffer = NULL, *arguments[2];
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
		buffer[strlen(buffer) - 1] = '\0';
		arguments[0] = buffer;
		arguments[1] = NULL;

		child_pid = fork();
		if (child_pid == -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execve(arguments[0], arguments, envr) == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
			wait(&stats);

		free(buffer);
		buffer = NULL;
	}
}
