#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *main - displays prompt
 *       gets input
 *       print back input
 *       do so endlessly until failure/ word exit entered
 *
 *Return: 0 on success
 */

int main(void)
{
	char *line = NULL;
	ssize_t charsRead;
	size_t size = 0;

	while (1)
	{
		printf("$ ");

		charsRead = getline(&line, &size, stdin);
		if (charsRead == -1)
		{
			fprintf(stderr, "Failed to read input\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (strcmp(line, "\n") == 0)
				continue;

			puts(line);
			if (strcmp(line, "exit\n") == 0)
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
		}
	}
}
