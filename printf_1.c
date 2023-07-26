#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom implementation of the printf function
 * @format: The format string containing the format specifiers
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	int var;
	char *str;
	char c;

	if (format == NULL)
		return (-1);

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
				c = va_arg(args, int);
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
			else if (format[var] == 'd' || format[var] == 'i')
			{
				int num_digits = 0;
				int divisor = 1;
				int num = va_arg(args, int);
				int temp;
				int i;
				int digit;

				if (num == 0)
				{
					num_digits = 1;
				}
				else
				{
					temp = num;
					while (temp != 0)
					{
						temp /= 10;
						num_digits++;
					}
				}

				if (num < 0)
				{
					putchar('-');
					count++;
					num = -num;
				}


				for (i = 1; i < num_digits; i++)
				{
					divisor *= 10;
				}

				while (divisor != 0)
				{
					digit = num / divisor;

					putchar('0' + digit);
					count++;
					num %= divisor;
					divisor /= 10;
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

