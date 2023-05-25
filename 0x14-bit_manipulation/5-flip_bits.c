#include "main.h"

/**
 * flip_bits - counts the number of bits needed to flip
 * to get from one number to another
 * @n: first number
 * @m: second number
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int j, cast = 0;
	unsigned long int present;
	unsigned long int unique = n ^ m;

	for (j = 63; j >= 0; j--)
	{
		present = unique >> j;
		if (present & 1)
			cast++;
	}

	return (cast);
}
