#include "main.h"
/**
 * print_pointer - That prints the value of a pointer variable
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: That calculate the active flags
 * @width: That get width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars to be printed
 */

int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_r = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	/* length = 2, for '0x' */
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0'
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
		extra_c = '+', length;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;

	/*return (write(1, &buffer[r], BUFF_SIZE - r - 1));*/
	return (write_pointer(buffer, ind, length, width,
				flags, padd, extra_c, padd_start));
}
/**
 * print_non_printable - That prints the ascii codes in hexa of
 * non printable characters
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: That calculate the active flags
 * @width: That get width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars to be printed
 */

int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int r = 0, offset = 0;
	char *string = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[r] != '\0')
	{
		if (printable(string[r]))
			buffer[r + offset] = string[r];
		else
			offset += append_hexa_code(string[r], buffer, r + offset);
		r++;
	}
	buffer[r + offset] = '\0';
	return (write(1, buffer, r + offset));
}
/**
 * print_reverse - That prints reverse string
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: That calculate the active flags
 * @width: That get width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars to be printed
 */

int print_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char *string;
	int r, count = 0;

	UNUSED(flags);
	UNUSED(width)
	UNUSED(precision);
	UNUSED(size);

	string = va_arg(types, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")Null(";
	}
	for (r = 0; string[r]; r++)
		;

	for (r = r - 1; r >= 0; r--)
	{
		char z = string[r];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - That prints the string in rot13
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: That calculate the active flags
 * @width: That get width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars to be printed
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char a;
	char *string;
	unsigned int c, d;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"

	string = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width)
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (c = 0; string[c]; c++)
	{
		for (d = 0; in[d]; d++)
		{
			a = out[d];
			write(1, &a, 1);
			count++;
			break;
		}
	}
	if (!in[d])
	{
		a = string[c];
		write(1, &a, 1);
		count++;
	}
	return (count);
}
