#include <unistd.h>
#include "main.h"

/**
 * _strlen - calculate the lenght of a str
 * @s: the string
 * Return: the lenght og s
*/
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;

	return (len);
}

/**
 * _print_char - print a character
 * @c: the char to printed
*/
void _print_char(char c)
{
	write(1, &c, 1);
}

/**
 * _print_str - print a string
 * @s: the string to print
*/
void _print_str(char *s)
{
	int i;

	for (i = 0; i < _strlen(s); i++)
	{
		_print_char(s[i]);
	}
}
