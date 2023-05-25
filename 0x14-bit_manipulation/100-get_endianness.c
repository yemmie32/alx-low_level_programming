#include "main.h"

/**
 * get_endianness - checks the endianness of a machine
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int j = 1;
	char *s = (char *) &j;

	return (*s);
}
