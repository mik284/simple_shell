#include <stdio.h>
#include <sys/stat.h>

/**
 *main - looks for files in the current PATH
 *@argc: number of arguments to main
 *@argv: array of arguments to main
 *
 *Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int i = 1;
	struct stat status;

	while (argv[i])
	{
		if (stat(argv[i], &status) == 0)
			printf("%s: FOUND\n", argv[i]);
		else
			perror("Error: ");
		i++;
	}
	return (0);
}
