#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned int is a palindrome
 * @n: unsigned int to be tested
 * Return: 1 if true, 0 if false
 */
int is_palindrome(unsigned long n)
{
	unsigned long copy = n, reverse = 0;

	if (n < 10)
		return (1);
	while (copy > 0)
	{
		reverse *= 10;
		reverse += copy % 10;
		copy /= 10;
	}
	if (n == reverse)
		return (1);
	return (0);
}
