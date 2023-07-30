#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom implementation of the printf function
 * @format: The format string containing the format specifiers
 *
 * Return: The number of characters printed (excluding the NULL byte)
 */

int _printf(const char *format, ...)
{
	int i = 0, j, k;
	int store;
	va_list args;
	int c;
	int array[MAX];

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'b')
		{
			store = va_arg(args, int);
			while (store > 0)
			{
				for (j = 0; j < MAX; j++)
				{
					c = store % 2;
					array[j] = c;
					store = store / 2;
				}
				for (k = MAX - 1; k >= 0; k--)
				{
					_putchar(array[k] + '0');
				}
			}
			i += 2;
		}
		else if (format[i] == '\n')
		{
			_putchar('\n');
			i++;
		}
		else
		{
			_putchar(format[i]);
			i++;
		}
	}

	va_end(args);

	return (i);
}
