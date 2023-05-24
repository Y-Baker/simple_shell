#include "stander_header.h"

/**
 * handle_home - handle (~) sign
 * @buffer: the string that have the command line
 * @envr: the environment vector
 * Return: the new buffer
*/

char *handle_home(char *buffer, char **envr)
{
	int index = 0, len, len_home;
	char *home, *new_buffer;

	home = get_envr_variable(envr, "HOME");
	if (!home)
		return (buffer);

	while (buffer[index])
	{
		if (buffer[index] == '~')
		{
			len_home = strlen(home);
			len = strlen(buffer) + len_home;
			new_buffer = malloc((len + 1) * sizeof(char));
			if (!new_buffer)
			{
				perror("Can't allocate memory\n");
				exit(EXIT_FAILURE);
			}

			strncpy(new_buffer, buffer, index);
			strncpy(new_buffer + index, home, len_home);
			strcpy(new_buffer + index + len_home, buffer + index + 1);
			new_buffer[len] = '\0';
			free(buffer);
			buffer = new_buffer;
		}
		index++;
	}
	return (buffer);
}
