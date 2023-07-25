/**
 * _printf - Implementation of Printf function
 * @format: format pinter
 * Return: the number of characters printed (excluding the null byte)
 */

#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	int var;

	va_start(args, format);

	for (var = 0; format[var] != '\0'; var++)
	{
		if (format[var] == '%')
		{
			var++;
			if (format[var] == '\0')
			{
				va_end(args);
				return (-1);
			}
			else if (format[var] == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (format[var] == 's')
			{
				char *str = va_arg(args, char*);

				while (*str != '\0')
				{
					putchar(*str);
					str++;
					count++;
				}
			}
			else if (format[var] == '%')
			{
				putchar('%');

				count++;
			}
			else
			{
				va_end(args);

				return (-1);
			}
		}
		else
		{
			putchar(format[var]);

			count++;
		}
	}

	va_end(args);

	return (count);
}
