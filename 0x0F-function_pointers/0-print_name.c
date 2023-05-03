#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - print name
 * @name: the string to add
 * @f: the pointer to function
 **/
void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
return;

f(name);
}
