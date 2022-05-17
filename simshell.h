#ifndef SSHELL_H
#define SSHELL_H
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*#include <sys/wait.h>*/
#include <sys/stat.h>
#include <dirent.h>
#include <stdarg.h>
#include <signal.h>
#include <string.h>
#define PROMPT "Owinnie@root $ "
/**
 *   * struct built_inside - for builtins
 *     * @built: name of command
 *       * @func: ptr to builtin
 *         */
typedef struct built_inside
{
		char *built;
			void (*func)(char *);
} blt;
extern char **environ;
int _strlen(char *str);
void _parse(char *line, size_t n, int count, char **av);
char **strtok_array(char *line, const char *delim, int tkn_count);
char *_strdup(char *src);
char **tkn_array(int tkn_count, char *line, const char *delim);
int built_ins(char **a_rray, char *line);
void (*list_built_ins(char *))(char *);
void exit_s(char *);
void env_s(char *);
void cd_s(char *);
void d_free(char **freed);
void s_free(int n, ...);
int _strcmp(char *s, char *s2);
int print_num(int n);
int find_path(char *s);
char *path_find(char *cmd);
void fork_a_child(char **s_array, char *line, int count, char **av);
void exec_err(char *av, int count, char *temp_cmd);
void print_err(char *av, int count, char *cmd);
char **sub_paths(int i, char *s);
char *search_dir(char **path_tkns, char *cmd);
char *build_path(char *dir, char *cmd);
int _write_char(char c);

#endif
