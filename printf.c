#include <stdarg.h>
#include <stdlib.h>
#include "main.h"


/**
 * _printf - print a string according to a format
 * @format: the format
 * Return: the lenght of the output
*/
int _printf(const char *format, ...)
{
    int i = 0, finish = 0, j = 0, *argsLen, numberOfFormat = 0, numberOfCHar = 0;
    va_list args;

    argsLen = malloc(sizeof(int) * _calculate_str_args_len(format, _strlen(format)));

    va_start(args, format);
    for (i = 0; i < _strlen(format); i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 's')
            {
                argsLen[j] = _strlen(va_arg(args, char *));
                numberOfCHar += argsLen[j];
                numberOfFormat++;
                j++;
            }
            else
            {
                va_arg(args, int);
                numberOfCHar += 1;
                numberOfFormat++;
            }
        }
    }
    va_end(args);
    
    va_start(args, format);
    j = 0;
    i = 0;
    while (finish == 0)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 's')
            {
                _print_str(va_arg(args, char *), argsLen[j]);
                j++;
            }
            else if (format[i + 1] == 'c')
                _print_char(va_arg(args, int));
            i += 2;
        }
        else
        {
            _print_char(format[i]);
            i++;
        }
        
        if (i >= _strlen(format))
            finish = 1;
    }
    va_end(args);

    return (_strlen(format) + numberOfCHar - numberOfFormat*2);
}