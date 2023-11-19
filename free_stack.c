#include "monty.h"

/**
 * free_stack - freeing the stack
 * @stack: The stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *traverse = stack;

	if (!traverse)
		return;

	while (stack)
	{
		traverse = stack->next;
		free(stack);
		stack = traverse;
	}
}
