#include "simshell.h"
/**
 * find_path - find path
 * @s: environ vars
 *
 * Return: -1, or index of environ var
 */
int find_path(char *s)
{
    int i, j, ln;

    ln = _strlen(s);
    for (i = 0; environ[i] != NULL; i++)
    {
        for (j = 0; j < ln; j++)
        {
            if (environ[i][j] != s[j])
                break;
        }
        if (j == ln && environ[i][j] == '=')
            return (i);
    }
    return (-1);
}
/**
 * path_find - path finder
 * @cmd: shell commads ... echo
 *
 * Return: NULL, or full path on success
 */
char *path_find(char *cmd)
{
    int i;
    char *dir;
    char **path_tkns;
    char *path;
    char *s = "PATH";

    i = find_path(s);
    path_tkns = sub_paths(i, s);
    if (path_tkns == NULL)
        return (NULL);
    dir = search_dir(path_tkns, cmd);
    if (dir == NULL)
    {
        d_free(path_tkns);
        return (NULL);
    }
    path = build_path(dir, cmd);
    if (path == NULL)
    {
        d_free(path_tkns);
        return (NULL);
    }
    d_free(path_tkns);
    return (path);
}
/**
 * sub_paths - break strs
 * @i: index of path
 * @s: str to be separated
 *
 * Return: NULL, or array of ptrs
 */
char **sub_paths(int i, char *s)
{
    int ln, tkn_count = 0;
    char *en_var;
    const char *delim = ":\n";
    char **path_tkns;

    ln = _strlen(s);
    en_var = environ[i] + (ln + 1);
    path_tkns = strtok_array(en_var, delim, tkn_count);
    if (path_tkns == NULL)
        return (NULL);
    return (path_tkns);
}
/**
 * search_dir - search the directories in path_tkns
 * @path_tkns: ptr to paths
 * @cmd: shell command
 *
 * Return: NULL, or dir with file
 */
char *search_dir(char **path_tkns, char *cmd)
{
    struct stat s_buf;
    char *wdir;
    char *buf = NULL;
    size_t n = 0;
    int s, i;

    wdir = getcwd(buf, n);
    if (wdir == NULL)
        return (NULL);
    if (cmd[0] == '/')
        cmd = cmd + 1;
    for (i = 0; path_tkns[i] != NULL; i++)
    {
        s = chdir(path_tkns[i]);
        if (s == -1)
        {
            perror("Error!");
            return (NULL);
        }
        s = stat(cmd, &s_buf);
        if (s == 0)
        {
            chdir(wdir);
            free(wdir);
            return (path_tkns[i]);
        }
    }
    chdir(wdir);
    free(wdir);
    return (NULL);
}
/**
 * build_path - make the path
 * @dir: directory
 * @cmd: command
 *
 * Return: NULL, or full path
 */
char *build_path(char *dir, char *cmd)
{
    int i, j, ln;
    char *built;

    if (dir == NULL || cmd == NULL)
        return (NULL);
    ln = (_strlen(dir) + 1) + (_strlen(cmd) + 1);
    built = malloc(sizeof(char) * ln);
    if (built == NULL)
        return (NULL);
    for (i = 0; i < ln; i++)
    {
        for (j = 0; dir[j] != '\0'; j++, i++)
            built[i] = dir[j];
        built[i] = '/';
        i++;
        for (j = 0; cmd[j] != '\0'; j++, i++)
            built[i] = cmd[j];
    }
    built[--i] = '\0';
    return (built);
}