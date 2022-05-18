#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


/**
 *main - executes ls -l /tmp in 5 different child processes
 *
 *Return: 0 on success, 1 on failure
 */

int main(void)
{
	int status, i = 0;
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (child_pid == 0)
			execve(argv[0], argv, NULL);
		else if (child_pid != 0)
			wait(&status);
		i++;
	}
	return (0);
}
