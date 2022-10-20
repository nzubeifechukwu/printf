#include <unistd.h>
/**
  * print_bin - print binary numbers
  * @num: numbar to be converted
  *
  * Return: void
  */
int print_bin(int num)
{
	char value, str;
	int len = 0;

	if (num < 0)
	{
		len++;
		str = '-';
		write(1, &str, 1);
		num = -num;
	}
	if (num > 2)
		len += print_bin(num / 2);

	value = (num % 2) + '0';
	write(1, &value, 1);

	return (len + 1);
}
