#include <stdlib.h>
#include <string.h>

/**
 *word_count - counts the number of words in a string
 *@str: the string to pass through the function
 *
 *Return: number of words in a string
 */

int word_count(char *str)
{
	int w_count = 0, i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && str[i - 1] == ' ')
			w_count++;
		i++;
	}
	return (w_count);
}

/**
 *split_string - splits a string into words
 *@string: the string to split into words
 *@delim: the delimiter to split string with
 *
 *Return: pointer an an array of words
 */

char **split_string(char *string, char *delim)
{
	char *token;
	char **string_array;
	int index = 0, w_count = 0;

	w_count = word_count(string);

	string_array = malloc(sizeof(char *) * w_count);
	if (string_array == NULL)
		return (NULL);

	token = strtok(string, delim);

	while (token != NULL)
	{
		string_array[index] = malloc(sizeof(char) * strlen(token));
		if (string_array[index] == NULL)
		{
			for (; index >= 0; index--)
				free(string_array[index]);
			free(string_array);
			return (NULL);
		}
		string_array[index] = token;
		token = strtok(NULL, delim);
		index++;
	}
	return (string_array);
}
