#include <stdio.h>
#include <stdlib.h>

/**
 *main - printf command line arguments
 *@argc: no. of arguments
 *@argv: character array of arguments
 *Return: 0 on success
 *
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char **p;

	for (p = argv; *p != NULL; p++)
	{
		puts(*p);
	}
	return (0);
}
