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
								/*DEFINATIONS*/
#define TRUE 1

								/*PROTOTYPE*/
void ready(char *argv[], char **envr);
char **_strtok(char *buffer, int size);
int set_shell_env(const char *variable, const char *value);
int unset_shell_env(const char *variable);
int execute_builtin_command(char **args);
void shell_loop();

#endif
