/**
 * _printf - Implementation of Printf function
 * @format: format pointer
 * Return: the number of characters printed (excluding the null byte)
 */

#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	int count = 0;
	va_list args;
	int var;
	char *str;

	va_start(args, format);

	for (var = 0; format[var] != '\0'; var++)
	{
		if (format[var] == '%')
		{
			var++;
			if (format[var] == '\0')
				return (-1);

			if (format[var] == '%')
			{
				putchar('%');
				count++;
			}
			else if (format[var] == 'c')
			{
				char c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (format[var] == 's')
			{
				str = va_arg(args, char*);
				if (str == NULL)
					str = "(null)";

				while (*str != '\0')
				{
					putchar(*str);
					str++;
					count++;
				}
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
