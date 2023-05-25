#include "stander_header.h"

/**
 * check_ready_path - check if the command line is an ready path
 * @arguments: the arguments arrays thar have command line
 * @filename: the name of your shell
 * @envr: the envronment vector
 * Return: 0 if not ready path
*/

int check_ready_path(char **arguments, char *filename, char **envr)
{
	if (!arguments)
		return (-1);
	if (arguments[0][0] == '/' || arguments[0][0] == '.')
		if (access(arguments[0], X_OK) == 0)
		{
			run_fork(arguments[0], arguments, filename, envr);
			return (TRUE);
		}
		else
		{
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", filename);
			perror("Fork Doesn't Done (:");
		}
	else if (arguments[0][0] == '~')
	{
		write(STDOUT_FILENO, "THIS HAVE (~) SIGN\n", 19);
	}
	return (0);
}
