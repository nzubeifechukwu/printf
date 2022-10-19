#include "main.h"
/**
  * print_bin - print binary numbers
  * @num: numbar to be converted
  * 
  * Return: void
  */
void print_bin(long num)

{
	char str,value;

	if (num < 0)
	{
		str = '-';
		write(1 ,&str, 1);
		num = -num;
	}
	if (num / 2)
		print_num(num / 2);
	value = (num % 2 + '0');
	write(1 ,&value, 1);
}
