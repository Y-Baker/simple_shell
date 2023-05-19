#include "stander_header.h"

/**
 * main - the main function
 *
 * Parameter:
 * @argc: argument count
 * @argv: array of argument
 * @envr: envionment vector
 *
 * Return: Always 0
*/

int main(int argc, char *argv[], char **envr)
{
	if (argc == 1)
		ready(argv, envr);
	else
		return (1);
	exit(0);
}
