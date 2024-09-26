#include "monty.h"

/**
 * push - Pushes an integer to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number where the opcode is located.
 * @value: The integer value to push onto the stack.
 */
void push(stack_t **stack, unsigned int line_number, char *value)
{
stack_t *new_node;
int n;

if (value == NULL || ((n = atoi(value)) == 0 && strcmp(value, "0") != 0))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = n;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number where the opcode is located.
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;

(void)line_number;  /* Avoid unused parameter warning */

while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
