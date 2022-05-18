#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simshell.h"
	ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	if (lineptr == NULL || n == NULL)
	{
		fputs("Error: Bad arguments.\n", stderr);
		return (-1);
	}
	if (stream == NULL)
	{
		fputs("Error: Bad file pointer", stderr);
		return (-1);
	}
	char chunk[128];
	if (*lineptr == NULL)
	{
		*n = sizeof(chunk);
		if ((*lineptr = malloc(*n)) == NULL)
		{
			perror("Unable to allocate memory for the buffer");
			return (-1);
		}
	}
	(*lineptr)[0] = '\0';
	while (fgets(chunk, sizeof(chunk), stream) != NULL)
	{
		if (*n - _strlen(*lineptr) < sizeof(chunk))
		{
			*n *= 2;
			if ((*lineptr = realloc(*lineptr, *n)) == NULL)
			{
				perror("Unable to reallocate mem");
				free(lineptr);
				return (-1);
			}
		}
		strcat(*lineptr, chunk);
		if ((*lineptr)[_strlen(*lineptr) - 1] == '\n')
		{
			return _strlen(*lineptr);
		}
	}
	return (-1);
}

int main(void)
{
	ssize_t get_l;
	char *bufer = NULL;
	size_t n = 0;

	printf("$ ");
	get_l = _getline(&bufer, &n, stdin);
	printf("%s\n", bufer);
	printf("%zu characters printed.\n", get_l);
	free(bufer);
	return (0);
}
