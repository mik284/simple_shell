#include "simshell.h"
/**
 *   * d_free - free ptrs
 *     * @freed: ptrs to be freed
 *       */
void d_free(char **freed)
{
	int i;

	for (i = 0; freed[i] != NULL; i++)
		free(freed[i]);
	free(freed);
}
/**
 *   * s_free - free ptrs to strs
 *     * @n: num of ptrs to free
 *       */
void s_free(int n, ...)
{
	int i;
	char *str;
	va_list list;

	va_start(list, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(list, char *);
		if (str == NULL)
			str = "(nil)";
		free(str);
	}
	va_end(list);
}
