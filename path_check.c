#include "stander_header.h"

/**
 * check_path - check if the file is in the path
 * @envr: the environment vector
 * @filename: the first argument of command line
 * Return: the fullpath and check ture if success
*/

command_t *check_path(char *filename, char **envr)
{
	char *path_env, *dir, *path_cy, *full_path;
	int size;
	command_t *new;

	new = malloc(sizeof(command_t));
	if (!new)
		exit(EXIT_FAILURE);
	path_cy = get_envr_variable(envr, "PATH");
	path_env = strdup(path_cy);
	dir = strtok(path_env, ":");
	while (dir)
	{
		size = strlen(dir) + (1 + strlen(filename));
		full_path = malloc(sizeof(char) * size);
		if (!full_path)
		{
			perror("Can't allocate memory\n");
			free(new);
			free(path_env);
			exit(EXIT_FAILURE);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, filename);
		if (access(full_path, X_OK) == 0)
		{
			new->path = full_path;
			new->check = TRUE;
			free(path_env);
			return (new);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_env);
	new->path = NULL;
	new->check = FALSE;
	return (new);
}
