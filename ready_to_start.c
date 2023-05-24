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
	char *buffer = NULL, **arguments, *prompt = "$ ";
	size_t size = 0;
	int builtin_return, path_return;
	command_t *new_command;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, strlen(prompt));
		ret = getline(&buffer, &size, stdin);
		if (ret == -1)
			own_free(buffer, NULL, NULL, F_EXIT);
		arguments = _strtok(buffer, ret, envr);
		path_return = check_ready_path(arguments, argv[0], envr);
		builtin_return = checks(arguments);
		if (builtin_return == 0 && path_return == 0)
		{
			new_command = check_path(arguments[0], envr);
			if (!new_command || new_command->path == NULL)
			{
				free(new_command);
				dprintf(STDERR_FILENO, "%s: No such file or directory\n", argv[0]);
			}
			else if (new_command->check == TRUE)
			{
				run_fork(new_command->path, arguments, argv[0], envr);
				own_free(new_command->path, NULL, NULL, F_TRUE);
				free(new_command);
			}
		}
		free(arguments);
		buffer = NULL;
	}
}
