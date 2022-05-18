#include "simshell.h"
/**
  * main - program gateway
  * @ac: num of av
  * @av: command line args passed
  *
  * Return: Always 0
  */
int main(__attribute__((unused))int ac, char **av)
{
	char *line;
	size_t n;
	int count = 0;

	signal(SIGINT, SIG_IGN);
	do {
		count++;
		line = NULL;
		n = 0;
		_parse(line, n, count, av);
	} while (1);
	return (0);
}
/**
  * _parse - parse commands and line of code
  * passed by the user
  * @line: ptr to str
  * @n: size_t
  * @count: num of commands entered
  * @av: program name
  */
void _parse(char *line, size_t n, int count, char **av)
{
	int i, tkn_count = 0;
	ssize_t get_ln;
	char **s_array;
	const char *delim = " \n\t";

	write(1, PROMPT, _strlen(PROMPT));
	get_ln = getline(&line, &n, stdin);
	if (get_ln != -1)
	{
		s_array = strtok_array(line, delim, tkn_count);
		if (s_array[0] == NULL)
		{
			s_free(2, s_array, line);
			return;
		}
		i = built_ins(s_array, line);
		if (i == -1)
			fork_a_child(s_array, line, count, av);
		for (i = 0; s_array[i] != NULL; i++)
			free(s_array[i]);
		s_free(2, s_array, line);
	}
	else
		exit_s(line);
}