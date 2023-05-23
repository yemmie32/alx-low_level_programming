#include <unistd.h>
/**
 * _putchar:write the character c to stdout
 * c: The character to print
 * to Return: On sucess (one) 1,  On error -1 will be returned
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
