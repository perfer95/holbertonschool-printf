#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, counter = 0;
	va_list args;

	if (format == NULL)
		return (0);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[++i] == 'c')
			{
				print_char(va_arg(args, int));
				counter++;
			}
			else if (format[++i] == 's')
			{
				print_string(va_arg(args, char *));
				counter++;
			}
			else if (format[++i] == '%')
			{
				write(1, "%", 1); /*just print '%'*/
				counter++;
			}
		}
		else if (format[i] == '\\' && format[i + 1] == 'n')
		{
			write(1, "\n", 1);
			i++;
			counter++;
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
 * Return: void
 */
void print_char(char c)
{
	write(1, &c, 1);
}

/**
 * print_string - function that prints strings
 * @s: string to print
 * Return: void
 */
void print_string(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}
