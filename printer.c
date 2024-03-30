#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, counter = 0;
	int *p_count = &counter;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				print_char(va_arg(args, int), p_count);
			else if (format[i + 1] == 's')
				print_string(va_arg(args, char *), p_count);
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				print_integer(va_arg(args, int), p_count);
			else if (format[i + 1] == '%')
				print_char('%', p_count);
			else if (format[i + 1] != '\0')
			{
				write(1, "%", 1);
				counter++;
				continue;
			}
			else
				return (-1);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			counter++;
		}
	}
	va_end(args);
	return (counter);
}

/**
 * print_char - function that prints chars
 * @c: char to print
 * @p_count: int pointer to count each print char
 * Return: void
 */
void print_char(char c, int *p_count)
{
	if (c == '%')
	{
		write(1, "%", 1);
		*p_count = *p_count + 1;
	}
	else if (c == '\0')
	{
		write(1, &c, 1);
		*p_count = *p_count + 1;
		return;
	}
	else
	{
		write(1, &c, 1);
		*p_count = *p_count + 1;
	}
}

/**
 * print_string - function that prints strings
 * @s: string to print
 * @p_count: int pointer to count each print char
 * Return: void
 */
void print_string(char *s, int *p_count)
{
	int i = 0;
	char *n = "(null)";

	if (s == NULL)
	{
		for (i = 0; n[i] != '\0'; i++)
		{
			write(1, &n[i], 1);
			*p_count = *p_count + 1;
		}
		return;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		write(1, &s[i], 1);
		*p_count = *p_count + 1;
	}
}

/**
 * print_integer - function that prints integers
 * @n: integer to print
 * @p_count: int pointer to count each print char
 * Return: void
 */
void print_integer(int n, int *p_count)
{
	char nums[20];
	int i = 0;
	int negative = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		*p_count = *p_count + 1;
		return;
	}
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		*p_count += 11;
		return;
	}
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	while (n != 0)
	{
		nums[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (negative)
	{
		nums[i++] = '-';
	}

	i--;

	while (i >= 0)
	{
		write(1, &nums[i], 1);
		*p_count = *p_count + 1;
		i--;
	}
}
