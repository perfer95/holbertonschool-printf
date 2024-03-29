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
		return (0);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c' || format[i + 1] == '%')
				print_char(va_arg(args, int), p_count);
			else if (format[i + 1] == 's')
				print_string(va_arg(args, char *), p_count);
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
	write(1, &c, 1);
	*p_count++;
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

	for (i = 0; s[i] != '\0'; i++)
	{
		write(1, &s[i], 1);
		*p_count++;
	}
}
