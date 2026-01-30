#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _putchar(char c);

/**
 * is_digit - checks if a string contains only digits
 * @s: string to check
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i;

	if (s == NULL || s[0] == '\0')
		return (0);

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * print_error - prints Error and exits with status 98
 */
void print_error(void)
{
	char *error = "Error";
	int i;

	for (i = 0; error[i]; i++)
		_putchar(error[i]);
	_putchar('\n');
	exit(98);
}

/**
 * multiply - multiplies two positive numbers
 * @num1: first number as string
 * @num2: second number as string
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, len_result, i, j, n1, n2, sum, carry, k;
	int *result;
	int start;

	len1 = strlen(num1);
	len2 = strlen(num2);
	len_result = len1 + len2;

	result = calloc(len_result, sizeof(int));
	if (result == NULL)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i + j + 1] += carry;
	}

	start = 0;
	while (start < len_result && result[start] == 0)
		start++;

	if (start == len_result)
	{
		_putchar('0');
		_putchar('\n');
		free(result);
		return;
	}

	for (k = start; k < len_result; k++)
		_putchar(result[k] + '0');
	_putchar('\n');

	free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error();

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	multiply(argv[1], argv[2]);

	return (0);
}
