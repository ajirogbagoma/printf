#include "main.h"
/**
 * print_char - That prints a character
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: That calculates active flags
 * @width: The width
 * @precision: The precise specification
 * @size: The specifier size
 * Return: The number of chars to be printed
 */

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char r = va_arg(types, int);

	return (handle_write_char(r, buffer, flags, width, precision, size));
}
/**
 * print_string - That prints a string
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: That calculates active flags
 * @width: The width
 * @precision: The precise specification
 * @size: The specifier size
 * Return: The number of chars to be printed
 */

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, r;
	char *string = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (string == NULL)
	{
		string = "(null)"
		if (precision >= 6)
			str = " ";
	}

	while (string[length] != '\0')
		length++;

	if (precision >= 0 && pricision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &string[0], length);

			for (r = width - length; r > 0; r--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (r = width - length; r > 0; r--)
				write(1, " ", 1);
			write(1, &string[0], length);
			return (width);
		}
	}
	return (write(1, string, length));
}
/**
 * print_percent - That prints percentage sign
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: That calculates active flags
 * @width: The width
 * @precision: The precise specification
 * @size: The specifier size
 * Return: The number of chars to be printed
 */

int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width)
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - That prints integers
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: That calculates active flags
 * @width: The width
 * @precision: The precise specification
 * @size: The specifier size
 * Return: The number of chars to be printed
 */

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int r = BUFF_SIZE - 2;
	int negative = 0;
	long int l = va_arg(types, long int);
	unsigned long int num;

	l = convert_size_number(l, size);

	if (l == 0)
		buffer[r--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)l;

	if (l < 0)
	{
		num = (unsigned long int)((-1) * l);
		negative = 1;
	}

	while (num > 0)
	{
		buffer[r--] = (num % 10) + '0';
		num /= 10;
	}
	r++;
	return (write_numbers(negative, r, buffer, flags, width,
				precision, size));
}

/**
 * print_binary - That prints unsigned number
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: That calculates active flags
 * @width: The width
 * @precision: The precise specification
 * @size: The specifier size
 * Return: The number of chars to be printed
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)

{
	unsigned int m, n, o, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	m = va_arg(types, unsigned int);
	n = 2147483648; /* (2 ^ 31) */
	a[0] = m / n;
	for (o = 1; o < 32, o++)
	{
		n /= 2;
		a[o] = (m / n) % 2;
	}
	for (o = 0, sum = 0, count = 0; o < 32, o++)
	{
		sum += a[o];
		if (sum || o == 31)
		{
			char r = '0' + a[o];

			write(1, &r, 1);
			count++;
		}
	}
	return (count);
}

