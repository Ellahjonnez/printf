#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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
					printer += _puts(va_arg(args, char *));
					i += 2;
					break;
				case '%':
					printer += _putchar('%');
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

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes the string s to stdout
 * @s: The string to print
 * Return: On success the length of the string.
 */

int _puts(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		_putchar(s[len]);
		len++;
	}
	return (len);
}
