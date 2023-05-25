#include "stander_header.h"

/**
 * remove_spaces - remove leading spaces
 * @str: the buffer
*/

void remove_spaces(char *str)
{
	int length = strlen(str);
	int i, j;

	for (i = 0; i < length; i++)
	{
		if (!isspace(str[i]))
			break;
	}

	for (j = 0; i < length; i++, j++)
		str[j] = str[i];

	str[j] = '\0';
}
