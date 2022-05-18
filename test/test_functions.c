#include "main.h"

/**
 *main - tests each function developed one by one
 *
 *Return: 0 on success
 */

int main(void)
{
// test _getline() function
	
	char *input = NULL;

	input = _getline();
	printf("_getline = %s\n", input);
	
//_getline works


// test word_count() function	

	int words = word_count(input);
	printf("words = %d\n", words);

// fail: exess words counted

	
// test split_string() function
	int i;

	char **arguments;
	arguments = split_string(input, " ");
	if (arguments == NULL)
		fprintf(stderr, "split_string failed!\n");
	
	for (i = 0; arguments[i]; i++)
		printf("split_string:aguments[%d] = %s\n", i, arguments[i]);
	
// split_string works
	

// test exit_shell() function
/*
	exit_shell(input);
	printf("exit_shell failed!\n");
*/
// exit_shell works


// test print_env() function

//	print_env(input);

// print_env works	


// test execute_builtins() function
/*	
	if (execute_builtin(input) == 0)
		exit(EXIT_SUCCESS);
	else
		printf("execute_builtins failed\n");
*/
// execute_builtin works
	
	
// test getPATH() function

//	int n;
/*	char **path_dir;

	path_dir = getPATH();
	if (!path_dir)
		fprintf(stderr, "getPATH failed!\n");
*/
//	for (n = 0; path_dir[n]; n++)
//		printf("%s\n", path_dir[n]);

// getPATH works


// test get_abs_pathname() function
/*
	char *abs_pathname;

	printf("Before get_abs_pathname function\n");
	abs_pathname = get_abs_pathname(arguments[0], path_dir);
	if (!abs_pathname)
		perror("Error: ");
	else
		arguments[0] = abs_pathname;
	printf("new arguments[0] = %s\n", arguments[0]);

	printf("After get_abs_pathname function = it  works\n");
*/
// get_abs_pathname() works	


// test create_process() function
/*
	int status;

	status = create_process(arguments);
	if (status == -1)
		printf("continue\n");
	else if (status == 0)
		printf("command executed\n");
	printf("it works\n");
*/
// create_process() works	
	return (0);
}
