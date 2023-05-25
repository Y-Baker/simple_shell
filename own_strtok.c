#include "stander_header.h"

/**
 * _strtok - add null between words
 * @buffer: pointer to the string
 * @size: number of chars
 * Return: this string with replace " " by \0
*/

char **_strtok(char *buffer, int size)
{
	char *s = NULL, **arguments;
	int count = 1;

	if (size <= 1)
		return (NULL);

	remove_spaces(buffer);
	arguments = malloc(sizeof(char *) * MAX_ARGV);
	if (!arguments)
	{
		perror("Can't allocate memory\n");
		exit(EXIT_FAILURE);
	}
	buffer[strcspn(buffer, "\n")] = '\0';
	strtok(buffer, " ");
	arguments[0] = buffer;
	s = strtok(NULL, " ");

	while (s != NULL)
	{
		arguments[count] = s;
		count++;
		s = strtok(NULL, " ");
	}

	arguments[count] = NULL;
	return (arguments);
}
