#include "simshell.h"
/**
 * strtok_array - break string to array
 * @line: str to be broken
 * @delim: str separator
 * @tkn_count: count num of tokens from str
 *
 * Return: array of tokens
 */
char **strtok_array(char *line, const char *delim, int tkn_count)
{
    char **s_array;
    char *s;
    char *tkn;

    s = _strdup(line);
    if (s == NULL)
        return (NULL);
    tkn = strtok(s, delim);
    for (tkn_count = 0; tkn != NULL; tkn_count++)
        tkn = strtok(NULL, delim);
    free(s);
    if (tkn_count == -1)
    {
        free(line);
        return (NULL);
    }
    s_array = tkn_array(tkn_count, line, delim);
    if (s_array == NULL)
    {
        free(line);
        return (NULL);
    }
    return (s_array);
}
/**
 * tkn_array - return array from str
 * @tkn_count: num of tokens gotten
 * @line: str to be split
 * @delim: str separator
 *
 * Return: array
 */
char **tkn_array(int tkn_count, char *line, const char *delim)
{
    int i;
    char **buffer;
    char *tkn;
    char *s;

    s = _strdup(line);
    buffer = malloc(sizeof(char) * (tkn_count + 1));
    if (buffer == NULL)
        return (NULL);
    tkn = strtok(s, delim);
    for (i = 0; tkn != NULL; i++)
    {
        buffer[i] = _strdup(tkn);
        tkn = strtok(NULL, delim);
    }
    buffer[i] = NULL;
    free(s);
    return (buffer);
}