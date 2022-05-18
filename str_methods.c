#include "simshell.h"
/**
  * _strdup - copy a str
  * @src: str to be duplicated
  *
  * Return: copied str
  */
char *_strdup(char *src)
{
	int i, ln;
	char *dest;

	ln = _strlen(src) + 1;
	dest = malloc(sizeof(char) * ln);
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
  * _strcmp - compare two strs
  * @s: str 1
  * @s2: str 2
  *
  * Return: 0 on success, -1 on failure
  */
int _strcmp(char *s, char *s2)
{
	int i;

	if (_strlen(s) != _strlen(s2))
		return (-1);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != s2[i])
			return (-1);
	}
	return (0);
}
/**
  * print_num - print number
  * @n: num to be printed
  *
  * Return: printed num
  */
int print_num(int n)
{
	int ln, div;
	unsigned int num;

	ln = 0;
	div = 1;
	for (num = n; num / div > 9; num++)
	{
		div *= 10;
	}
	for (; div != 0; )
	{
		ln += _write_char('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (ln);
}
/**
  * _strlen - find len of string
  * @str: string to find len
  *
  * Return: 0, or len of string
  */
int _strlen(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
/**
  * _write_char - Writes a character to stdout
  * @c: Character that will be written to stdout
  * Return: Upon success how many characters were written.
  */
int _write_char(char c)
{
	return (write(1, &c, 1));
}