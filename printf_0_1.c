#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_n - writes integers to stdout
 * @n: integer to write
 *
 * Return: number of digits of n
 */
int print_int(int n)
{
	char num;
	int n_len = 0;

	if (n < 0)
	{
		num = '-';
		n_len++;
		write(1, &num, 1);
		n = -n;
	}

	if (n > 9)
	{
		num = (n % 10) + '0';
		n_len++;
		n = n / 10;

		if (n > 0)
		{
			n_len += print_int(n);
		}

		write(1, &num, 1);
	}
	else
	{
		num = n + '0';
		n_len++;
		write(1, &num, 1);
	}

	return (n_len);
}

/**
 * _printf - prints formatted string (handles %%, %c, %s, %d, %i)
 * @format: pointer to string to print
 *
 * Return: length of printed string
 */
int _printf(const char *format, ...)
{
	int i = 0, len = 0, c;
	char *s;
	va_list ap;

	va_start(ap, format);
	if (format)
	{
		while (*(format + i))
		{
			switch (*(format + i))
			{
				case '%':
					i++;
					switch (*(format + i))
					{
						case '%':
							write(1, "%", 1);
							i++;
							len += 1;
							continue;
						case 'c':
							c = va_arg(ap, int);
							write(1, &c, 1);
							i++;
							len += 1;
							continue;
						case 's':
							s = va_arg(ap, char *);
							write(1, s, _strlen(s));
							i++;
							len += _strlen(s);
							continue;
						case 'd':
							len += print_int(va_arg(ap, int));
							i++;
							continue;
						case 'i':
							len += print_int(va_arg(ap, int));
							i++;
							continue;
					}
			}
			write(1, format + i, 1);
			i++;
			len += 1;
		}
	}
	va_end(ap);
	return (len);
}
