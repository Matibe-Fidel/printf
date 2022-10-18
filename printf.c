#include <stdarg.h>
#include "main.h"


/**
 * _printf - print a string according to a format
 * @format: the format
 * Return: the lenght of the output
*/
int _printf(const char *format, ...)
{
	int i = 0, numberOfFormat = 0, numberOfChar = 0;
	char *tmp;

	va_list args;

	va_start(args, format);

	while (i < _strlen(format))
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 's')
			{
				tmp = va_arg(args, char *);
				_print_str(tmp);
				numberOfChar += _strlen(tmp);
				numberOfFormat++;
			}
			else if (format[i + 1] == 'c')
			{
				_print_char(va_arg(args, int));
				numberOfChar++;
				numberOfFormat++;
			}
			else if (format[i + 1] == '%')
			{
				_print_char('%');
				numberOfChar++;
				numberOfFormat++;
			}
			i += 2;
			continue;
		}
		_print_char(format[i]);
		i++;
	}
	va_end(args);

	return (_strlen(format) + numberOfChar - (numberOfFormat * 2));
}
