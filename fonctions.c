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
char *_print_str(char *s)
{
	int i;

	for (i = 0; i < _strlen(s); i++)
	{
		_print_char(s[i]);
	}

	return (s);
}

/**
 * _int_len - calculate the lenght of a str
 * @s: the string
 * Return: the lenght og s
*/
int _int_len(int i)
{
	int len = 0, j = i;

	while (j != 0)
	{
		j = (int)(j / 10);
		len++;
	}

	if (i < 0)
		len++;
	
	
	return (len);
}

/**                                                                                                                                                     
 *print_number - check the code                                                                                                                         
 *@c: the parameter                                                                                                                                     
 */                                                                                                                                                     
void _print_int(int c)                                                                                                                                
{
        unsigned int i = c;
                                                                                                                                                        
        if (c < 0)
        {
            _print_char('-');
            i = -i;
        }
        if ((i / 10) > 0)
            _print_int(i / 10);

        _print_char((i % 10) + '0');
}
