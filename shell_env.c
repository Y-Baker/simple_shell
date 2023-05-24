#include "stander_header.h"

/**
 * set_shell_env - set the value of a shell environment variable
 *
 * @variable: the name of the environment variable
 * @value: the value to be set
 *
 * Return: 0 on success, -1 on failure
 */
int set_shell_env(const char *variable, const char *value)
{
	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "set_shell_env: Missing arguments\n");
		return (-1);
	}

	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}

/**
 * unset_shell_env - unset a shell environment variable
 *
 * @variable: the name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int unset_shell_env(const char *variable)
{
	if (variable == NULL)
	{
		fprintf(stderr, "unset_shell_env: Missing argument\n");
		return (-1);
	}

	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}

/**
 * execute_builtin_command - execute a built-in shell command
 *
 * @args: the arguments for the command
 *
 * Return: 0 on success, -1 on failure
 */
int execute_builtin_command(char **args)
{
	if (strcmp(args[0], "setenv") == 0)
	{
		return (set_shell_env(args[1], args[2]));
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		return (unset_shell_env(args[1]));
	}

	return (-1);
}

/**
 * shell_loop - main loop of the shell
 */
void shell_loop(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t bytes_read;

	while (1)
	{
		printf("> ");
		bytes_read = getline(&line, &line_size, stdin);
		if (bytes_read == -1)
		{
			perror("getline");
			break;
		}

		char *token;
		char **args = malloc(sizeof(char *) * line_size);
		int arg_count = 0;

		token = strtok(line, " \t\n");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " \t\n");
		}
		args[arg_count] = NULL;

		if (arg_count > 0 && execute_builtin_command(args) == -1)
		{
			printf("Command not found: %s\n", args[0]);
		}

		free(args);
	}

	free(line);
}


/**
 *main - Entry point of the shell program
 *
 *Description: This function runs the main loop of the shell, allowing the user
 *to input commands and executing them accordingly.
 *
 *Return: 0 on successful termination
 */
int main(void)
{
	shell_loop();
	return (0);
}

