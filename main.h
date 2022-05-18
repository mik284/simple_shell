#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
<<<<<<< HEAD
/*#include <sys/wait.h>*/
=======
#include <sys/wait.h>
>>>>>>> 9f9b277ef8df0af0a4d78ee7c63a8c5c7149b147

extern char **environ;

/**
 *struct Builtins - matches a builtin argument with function to execute it
 *@name: name of the builtin to execute
 *@function: pointer to the function that execute that builtin
 */

typedef struct Builtins
{
	char *name;
	void (*function)(char *input);
} builtins;


char *_getline(void);
int word_count(char *str);
char **split_string(char *str, char *delim);
void print_env(char *input);
void exit_shell(char *input);
int execute_builtin(char *input);
char **getPATH(void);
char *get_abs_pathname(char *argument);
int create_process(char **arguments);

#endif
