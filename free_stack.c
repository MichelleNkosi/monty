#include "monty.h"

/**
 * free_stack - Frees a stack_t linked list.
 * @stack: Double pointer to the head of the stack.
 */
void free_stack(stack_t *stack)
{
stack_t *temp;

while (stack != NULL)
{
temp = stack;
stack = stack->next;
free(temp);
}
}
