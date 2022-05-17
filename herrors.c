#include "simshell.h"
/**
 *   * exec_err - displays execution errs
 *     * @av: program name
 *       * @count: num of commands running
 *         * @temp_cmd: failing command
 *           */
void exec_err(char *av, int count, char *temp_cmd)
{
	print_err(av, count, temp_cmd);
	write(1, ": ", 2);
	perror("");
	exit(1);
}
/**
 *   * print_err - print err message
 *     * @av: program name
 *       * @count: num of commands passed
 *         * @cmd: command not found
 *           */
void print_err(char *av, int count, char *cmd)
{
	write(1, &av, _strlen(av));
	write(1, ": ", _strlen(": "));
	print_num(count);
	write(1, ": ", _strlen(": "));
	write(1, &cmd, _strlen(cmd));
}
