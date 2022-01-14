#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);

/**
 * digit_check - checks if a string is only numerical chars
 * @string: input string
 * Return: formatted string
 */
char *digit_check(char *string)
{
	int i, offset = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '0' && offset == i)
			offset++;
		if (string[i] < '0' || string[i] > '9')
		{
			printf("Error\n");
			exit(98);
		}
	}
	if (offset == i)
	{
		_putchar('0');
		_putchar('\n');
		exit(0);
	}
	return (string + offset);
}

/**
 * mul - multiplies two numbers of any size
 * @num1: first number
 * @num2: second number
 */
void mul(char *num1, char *num2)
{
	int i, j, k, len1 = 0, len2 = 0;
	char *total;
	int digit, carry, product;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	printf("%s %s\n", num1, num2);
	total = malloc(sizeof(char) * (len1 + len2));
	if (total == NULL)
		exit(1);

	for (i = 0; i < (len1 + len2); i++)
		total[i] = '0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			k = i + j + 1;
			product = ((num1[i] - '0') * (num2[j] - '0')) + carry;
			digit = product % 10;
			carry = product / 10;
			if (total[k] == '0')
			{
				total[k] += digit;
			}
			else
			{
				digit += total[k] - '0';
				total[k] = (digit % 10) + '0';
				carry += digit / 10;
			}
		}
		while (carry)
		{
			total[--k] += carry % 10;
			carry /= 10;
		}
	}
	total = digit_check(total);
	for (i = 0; i < (len1 + len2); i++)
		_putchar(total[i]);
	_putchar('\n');
}

/**
 * main - Let's begin
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = digit_check(argv[1]);
	num2 = digit_check(argv[2]);
	mul(num1, num2);
	exit(0);
}
