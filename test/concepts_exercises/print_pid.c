#include <unistd.h>
#include <stdio.h>

/**
 *main - prints the PID of its parent process
 *
 *Return: void
 */

int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();

	printf("%u\n", my_ppid);

	return (0);
}
