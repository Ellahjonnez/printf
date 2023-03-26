#include "main.h"
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

	while(format[i] != '\0')
	{
		if(format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					printer += _putchar( va_arg(args, int));
					i += 2;
					break;
				case 's':
					printer += _putchar(va_arg(args, char));
					break;
					i += 2;
				case '%':
					printer += _putchar('%');
					i += 2;
					break;
				default:
					i++;
					continue;
				}
			printer += _putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return(printer);
}

/**
 * _putchar - writes the character c to stdout
 * @c : The character to print
 * Return : On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
