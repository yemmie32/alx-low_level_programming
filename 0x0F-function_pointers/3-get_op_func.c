#include "3-calc.h"
#include <stdlib.h>
/**
 * get_op_func - Determine the appropriate function per task given by the user.
 * @s: The operator given as argument.
 * Return: A pointer to the function consistent with the operator given
 */
int (*get_op_func(char *s))(int, int)
{
op_t ops[] = {
{"+", op_add},
{"-", op_sub},
{"*", op_mul},
{"/", op_div},
{"%", op_mod},
{NULL, NULL},
};
int i = 0;

while (ops[i].op != NULL && *(ops[i].op) != *s)
i++;

return (ops[i].f);
}
