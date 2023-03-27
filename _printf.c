#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - to produce output according to a format
 * @format: The format string is composed of zero or more directives.
 * Return: the number of characters printed
 * excluding the null byte used to end output to strings
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printer = 0;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					printer += _putchar(va_arg(args, int));
					i += 2;
					break;
				case 's':
					printer += print_string(va_arg(args, char *));
					i += 2;
					break;
				case '%':
					printer += _putchar('%');
					i += 2;
					break;
				case 'd':
					printer += print_decimal(va_arg(args, int));
					i += 2;
					break;
				case 'i':
					printer += print_decimal(va_arg(args, int));
					i += 2;
					break;
				case 'b':
					printer += print_binary(va_arg(args, int));
					i += 2;
					break;
				case 'u':
					printer += print_unsigned(va_arg(args, unsigned int));
					i += 2;
					break;
				default:
					i++;
					continue;
			}
		}
		else
		{
			printer += _putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (printer);
}

