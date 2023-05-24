#include "stander_header.h"

/**
 * own_free - free more than one
 * @p1: the first pointer
 * @p2: the second one
 * @p3: the third one
 * @stats: the state
 * (-2) with exit
 * (0)  with nothing
*/
void own_free(char *p1, char *p2, char *p3, int stats)
{
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	if (p3)
		free(p3);

	switch (stats)
	{
	case F_EXIT:
		exit(EXIT_FAILURE);
	default:
		break;
	}
}
