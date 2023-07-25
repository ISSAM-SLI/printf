#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

/**
 * _printf - Custom implementation of printf function.
 * @format: A string containing format specifiers.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	unsigned int j;

	va_start(args, format);
	for (j = 0; format[j] != '\0'; j++)
	{
		if (format[j] == '%')
		{
			j++;
			if (format[j] == '%')
			{
				putchar('%');
				count++;
			}
			else if (format[j] == 'c')
			{
				char c = (char) va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (format[j] == 's')
			{
				const char *str = va_arg(args, const char *);
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
			putchar(format[j]);
			count++;
		}
	}

	va_end(args);
	return count;
}
