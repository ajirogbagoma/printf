#include "main.h"
/**
 * get_precision - That calculates the precision for painting
 * @list: The argument list
 * @format: The formatted string in which the argument is printed
 * @i: The list of printed argument
 * Return: Precision
 */

int get_precision(const char *format, int *i, va_list list)
{
	int recent_i = *i + 1;
	int precision = -1;

	if (format[recent_i] != '.')
		return (precision);

	precision = 0;

	for (recent_i += 1; format[recent_i] != '\0'; recent_i++)
	{
		if (digit(format[recent_i]))
		{
			precision *= 10;
			precision += format[recent_i] - '0';
		}
		else if (format[recent_i] == '*')
		{
			recent_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = recent_i - 1;

	return (precision);
}
