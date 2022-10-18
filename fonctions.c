#include <stdio.h>
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
    
    return len;
}

/**
 * _print_str - print a string
 * @s: the string to print
 * @len: the lenght of s
*/
void _print_str(char *s, int len)
{
    write(1, s, len);   
}

/**
 * _calculate_str_args_len - calculate the number of '%' in a str
 * @s: the string
 * @len: the lenght of s
 * Rteurn: the number of '%'
*/
int _calculate_str_args_len(const char *s, int len)
{
    int strArgsLen = 0, i;

    for (i = 0; i < len; i++)
    {
        if (s[i] == '%' && s[i + 1] == 's')
            strArgsLen++;
    }

    return strArgsLen;
}

/**
 * _print_char - print a character
 * @c: the char to printed
*/
void _print_char(char c)
{
    write(1, &c, 1);
}