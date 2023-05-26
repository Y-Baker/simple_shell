#ifndef MAIN_H
#define MAIN_H
								/*HEADERS*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>

								/*STRUCTURE*/

/**
 * struct command - store the full path
 * @path: pointer to the path
 * @check: 1 if finded and -1 if failed
 */
typedef struct  command
{
	char *path;
	int check;
} command_t;

								/*DEFINATIONS*/
#define TRUE		1
#define FALSE		-1
#define MAX_ARGV	20
/* free */
#define F_EXIT		-2
#define F_TRUE		0

								/*PROTOTYPE*/
void ready(char *argv[], char **envr);
char **_strtok(char *buffer, int size);
int check_builtin(char **arguments, char *buffer, char **envr);
void run_fork(char *path, char **arguments, char *argv, char **envr);
command_t *check_path(char *filename, char **envr);
char *get_envr_variable(char *envp[], char *var);
void own_free(char *p1, char *p2, char *p3, int stats);
int check_ready_path(char **arguments, char *filename, char **envr);
int checks(char **arguments, char *buffer, char **envr);
int execute_builtin_command(char **args);
int set_shell_env(const char *variable, const char *value);
int unset_shell_env(const char *variable);
void remove_spaces(char *str);
void own_exit(char *buffer, char **arguments);
void own_cd(char **args, char **envr);

#endif
