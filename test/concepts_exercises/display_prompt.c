#include <stdio.h>
#include <stdlib.h>

/**
 *main - gets input from user and displays it on next line
 *
 *Return: 0 on success
 */

int main(void)
{
	char *line = NULL;
	ssize_t charsRead;
	size_t size = 0;

	printf("$ ");

	charsRead = getline(&line, &size, stdin);
	if (charsRead == -1)
	{
		fprintf(stderr, "Failed to read input\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		puts(line);
	}

	free(line);
	exit(EXIT_SUCCESS);
}
