#include "palindrome.h"
/**
 * is_palindrome - checks if an long int is palinrome
 * @n: number
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long temp, module, reverse = 0;

	temp = n;
	while (n > 0)
	{
		module = n % 10;
		reverse = (reverse * 10) + module;
		n = n / 10;
	}

	if (temp == reverse)
		return (1);

	return (0);
}