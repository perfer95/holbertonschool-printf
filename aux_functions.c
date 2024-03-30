#include "main.h"

/**
 * num_digits - function that count digits
 * @num: num to check
 * Return: int with the number of digits
 */
int num_digits(long int num)
{
	int count = 0;

	if (num == 0)
	{
		return (1);
	}

	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
