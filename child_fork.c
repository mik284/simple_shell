#include "simshell.h"
/**
 *   * fork_a_child - create a child process
 *     * @s_array: array of ptrs to strs
 *       * @line: line read
 *         * @count: num of commands
 *           * @av: program name
 *             */
void fork_a_child(char **s_array, char *line, int count, char **av)
{
	int i, status, c;
	pid_t id;
	struct stat buf;
	char *cmd;
	char *temp_cmd;

	id = fork();
	if (id == 0)
	{
		temp_cmd = s_array[0];
		cmd = path_find(s_array[0]);
		if (cmd == NULL)
		{
			c = stat(temp_cmd, &buf);
			if (c == -1)
			{
				print_err(av[0], count, temp_cmd);
				write(1, ": doesn't exist\n", _strlen(": doesn't exist\n"));
				s_free(2, line, temp_cmd);
				for (i = 1; s_array[i]; i++)
					free(s_array[i]);
				free(s_array);
				exit(100);
			}
			cmd = temp_cmd;
		}
		s_array[0] = cmd;
		if (s_array[0] != NULL)
		{
			if (execve(s_array[0], s_array, environ) == -1)
				exec_err(av[0], count, temp_cmd);
		}
	}
	else
		wait(&status);
}
