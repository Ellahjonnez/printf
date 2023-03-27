#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *);
int print_decimal(int value);
int print_binary(int number);
int print_unsigned(unsigned int number);


#endif /* End of MAIN_H */
