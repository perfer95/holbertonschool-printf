#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, counter = 0;
	char c;
	char *s;
	va_list args;

	if (format == NULL)
		return (0);

	va_start(args, format);
	for (i = 0; format[i] != '0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				c = va_arg(args, char);
				write(1, &c, 1);
				counter++;
			}
			else if (format[i + 1] == 's')
			{
				*s = va_arg(args, char *);
				while (*s)
				{
					write(1, s, 1);
					s++;
					counter++;
				}
			}
			else if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				counter++;
			}
			else
			{
				write(1, format[i], 1);
				counter++;
			}
		}
	}
	va_end(args);
	return (counter);
}
