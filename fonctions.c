
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

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