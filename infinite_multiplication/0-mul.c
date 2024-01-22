#include <stdlib.h>

int _putchar(char c);


/**
 *	reverse_buffer - reverses buffer's value
 *
 * @r: buffer
 * @size: size of buffer
 * Return: r
 */

char	*reverse_buffer(char *r, int size)
{
	int	i, nb;

	i = 0;
	while (i < size)
	{
		size--;
		nb = r[i];
		r[i] = r[size];
		r[size] = nb;
		i++;
	}
	return (r);
}

/**
 * _puts_error - prints error or prints string depending on parameter
 * @error: parameter to chose how to use function
 * @str: string to print
 * Return: 98 if error, 0 if not
 */
int		_puts_error(int error, char *str)
{
	if (error)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}
	while (*str)
		_putchar(*str++);
	_putchar('\n');
	return (0);
}

/**
 * infinite_add - adds number to string of numbers
 * @sum: String of numbers
 * @nb: number to add
 * @index: decimal place of number
 * @len: length of sum string
 */
void	infinite_add(char *sum, int nb, int index, int len)
{
	int	tenth = 0;

	sum[index] += nb % 10;
	sum[index + 1] += nb / 10;
	while (index < len)
	{
		sum[index] += tenth;
		tenth = 0;
		if (sum[index] > '9')
			tenth = 1;
		sum[index] = (sum[index] - '0') % 10 + '0';
		index++;
	}
}

/**
 * infinite_mul - multiplies two numbers in string format
 * @n1: number 1
 * @n2: number 2
 * @sum: array to store result of multiplication
 * @len: size of sum arrays
 */
void	infinite_mul(char *n1, char *n2, char *sum, size_t len)
{
	int	i, j, nb;

	for (i = 0; n1[i]; i++)
		;
	reverse_buffer(n1, i);
	for (i = 0; n2[i]; i++)
		;
	reverse_buffer(n2, i);
	for (i = 0; (size_t)i < len; i++)
		sum[i] = '0';
	for (i = 0; n1[i]; i++)
	{
		for (j = 0; n2[j]; j++)
		{
			nb = (n1[i] - '0') * (n2[j] - '0');
			infinite_add(sum, nb, i + j, len);
		}
	}
	reverse_buffer(sum, len);
	i = 0;
	while (sum[i] && sum[i] == '0' && sum[i + 1])
		i++;
	_puts_error(0, sum + i);
}


/**
 * main - checks for error and prepares variable for multiplication
 * @ac: number of arguments
 * @av: array of arguments
 * Return: Always 0
 */
int		main(int ac, char **av)
{
	unsigned int	i, size;
	char	*result;

	if (ac != 3)
		return (_puts_error(1, NULL));
	for (i = 0; av[1][i]; i++)
		if (av[1][i] < '0' || av[1][i] > '9')
			return (_puts_error(1, NULL));
	size = i;
	if (!i)
		return (_puts_error(1, NULL));
	for (i = 0; av[2][i]; i++)
		if (av[2][i] < '0' || av[2][i] > '9')
			return (_puts_error(1, NULL));
	if (!i)
		return (_puts_error(1, NULL));
	size += i;
	result = malloc((sizeof(*result) + 1) * size);
	if (!result)
		return (_puts_error(1, NULL));
	for (i = 0; i < size; i++)
		result[i] = '0';
	result[i] = '\0';
	infinite_mul(av[1], av[2], result, size);
	free(result);
	result = NULL;
	return (0);
}
