#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - counts the number of unique nodes in a looped listint_t linked list.
 * @head: pointer to the head of the listint_t to be checked.
 * Return: 0 if the list is not looped
 * Or the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
const listint_t *cat, *dog;
size_t nodes = 1;

if (head == NULL || head->next == NULL)
return (0);

cat = head->next;
dog = (head->next)->next;

while (dog)
{
if (cat == dog)
{
cat = head;
while (cat != dog)
{
nodes++;
cat = cat->next;
dog = dog->next;
}

cat = cat->next;
while (cat != dog)
{
nodes++;
cat = cat->next;
}

return (nodes);
}

cat = cat->next;
dog = (dog->next)->next;
}

return (0);
}

/**
 * print_listint_safe - rints a listint_t list
 * @head: pointer to the head of the listint_t list.
 * Return: number of nodes on the list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t nodes, index = 0;

nodes = looped_listint_len(head);

if (nodes == 0)
{
for (; head != NULL; nodes++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}

else
{
for (index = 0; index < nodes; index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}

printf("-> [%p] %d\n", (void *)head, head->n);
}

return (nodes);
}
