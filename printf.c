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
    int i = 0;
    int finish = 0;
    int numberOfFormat = 0;
    int numberOfChar = 0;
    va_list args;
    
    va_start(args, format);
    while (finish == 0)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 's')
            {
                _print_str(va_arg(args, char *));
                numberOfFormat++;
            }
            else if (format[i + 1] == 'c')
            {
                _print_char(va_arg(args, int));
                numberOfFormat++;
            }
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

    return (_strlen(format) + numberOfChar - numberOfFormat*2);
}