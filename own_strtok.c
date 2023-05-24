#include "stander_header.h"

/**
 * _strtok - add null between words
 * @buffer: pointer to the string
 * @size: number of chars
 * @envr: environment vector
 * Return: this string with replace " " by \0
*/

char **_strtok(char *buffer, int size, char **envr)
{
	char *s = NULL, **arguments;
	int count = 1;

	if (size <= 1)
		return (NULL);

	buffer = handle_home(buffer, envr);
	arguments = malloc(sizeof(char *) * MAX_ARGV);
	if (!arguments)
	{
		perror("Can't allocate memory\n");
		exit(EXIT_FAILURE);
	}
	buffer[strcspn(buffer, "\n")] = '\0';
	strtok(buffer, " ");
	arguments[0] = strdup(buffer);
	s = strtok(NULL, " ");

	while (s != NULL)
	{
		arguments[count] = strdup(s);
		count++;
		s = strtok(NULL, " ");
	}

	arguments[count] = NULL;
	free(buffer);
	return (arguments);
}
