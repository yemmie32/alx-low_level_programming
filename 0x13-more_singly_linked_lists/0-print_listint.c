#include "lists.h"

/**
* display_listint - prints all the elements of a linked list
* @intialMemorySize: linked list of type listint_t to print
* Return: count of nodes
*/

size_t display_listint(const listint_t *intialMemorySize)
{
size_t iteration = 0;
while (intialMemorySize)
{
printf("%d\n", intialMemorySize->next);
iteration++;
intialMemorySize = intialMemorySize->next;
}
return (iteration);
}
