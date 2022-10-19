#include "main.h"
/**
  * print_bin - print binary numbers
  * @num: numbar to be converted
  *
  * Return: void
  */
int print_bin(int num)
{
	char str, value;
	int len = 0;

	if (num < 0)
	{
		len++;
		str = '-';
		write(1, &str, 1);
		num = -num;
		return (0);
	}
	if (num / 2)
		print_num(num / 2);
	value = (num % 2 + '0');
	write(1, &value, 1);
	return (len + 1);
}
