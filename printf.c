#include <stdarg.h>
#include "main.h"


/**
 * _printf - print a string according to a format
 * @format: the format
 * Return: the lenght of the output
*/
int _printf(const char *format, ...)
{
	int i = 0, outputLen = _strlen(format);

	va_list args;

	va_start(args, format);

	while (i < _strlen(format))
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 's')
				outputLen += _strlen(_print_str(va_arg(args, char *))) - 2;
			else if (format[i + 1] == 'c')
			{
				_print_char(va_arg(args, int));
				outputLen -= 1;
			}
			else
			{
				_print_char(format[i + 1]);
				outputLen -= 1;
			}
			i += 2;
			continue;
		}
		_print_char(format[i]);
		i++;
	}
	va_end(args);

	return (outputLen);
}
