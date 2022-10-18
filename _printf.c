#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
  * _printf - print string
  * @format: string to be printed and formated
  *
  * Return: string len
  */

int _printf(const char *format, ...)

{
	int strlen1 = 0, strlen2 = 0, i;
	va_list ap;
	char *ptr;

	va_start(ap, format);

	if (format != NULL)
	{
		while (format[strlen1])
			strlen1++;
		for (i = 0; i <= strlen1; i++)
		{
			if (format[i] == '%')
			{
				i++;
				if (format[i] == 'c')
				{
					int j = va_arg(ap, int);

					write(1, &j, 1);
				}
				else if (format[i] == 's')
				{
					ptr = va_arg(ap, char *);
					while (ptr[strlen2])
						strlen2++;
					write(1, ptr, strlen2);
				}
			}
			else
			{
				write(1, &format[i], 1);
			}
		}
		va_end(ap);
		return (strlen1);
	}
	return (0);
}
