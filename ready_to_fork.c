#include "stander_header.h"

/**
 * run_fork - excute fork function and run the new process
 * @arguments: the arguments
 * @argv: the first argument that is the name of the program
 * @envr: the environment vector
 * @path: the path of the program
*/

void run_fork(char *path, char **arguments, char *argv, char **envr)
{
	int stats;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		write(STDERR_FILENO, "Can't Fork :(\n", 14);
		free(arguments);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0 && arguments)
	{
		if (execve(path, arguments, envr) == -1)
		{
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", argv);
			return;
		}
	}
	else
		wait(&stats);
}
