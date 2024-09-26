#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Doubly linked list structure for stack or queue */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/* Opcode and function structure */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void free_stack(stack_t *stack);
int custom_getline(char **lineptr, size_t *n, FILE *stream);
void push(stack_t **stack, unsigned int line_number, char *value);
void pall(stack_t **stack, unsigned int line_number);
/* Add other function prototypes here */

#endif /* MONTY_H */
