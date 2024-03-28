#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	char c;
	char *s;
	va_list args;

	if (format == NULL)
		return (0);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				counter++;
			}
			else if (*format == 's')
			{
				*s = va_arg(args, char *);
				while (*s)
				{
					write(1, s, 1);
					s++;
					counter++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				counter++;
			}
			else
			{
				write(1, *format, 1);
				counter++;
			}
		}
		format++;
	}
	va_end(args);
	return (counter);
}
