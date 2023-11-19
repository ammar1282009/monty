#include "monty.h"

/**
 * swap - Swaps the top two elements
 * @stack: The stack
 * @line_number: Line numbers of .m files
 *
 * Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *nth_2 = NULL;
	int temp = 0;

	if (top)
	{
		nth_2 = top->next;

		if (nth_2)
		{
			temp = top->n;
			top->n = nth_2->n;
			nth_2->n = temp;
			return;
		}
	}

	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * add - adds the top two elements
 * @stack: The stack
 * @line_number: Line numbers of .m files
 *
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *nth_2 = NULL;

	if (top)
	{
		nth_2 = top->next;

		if (nth_2)
		{
			nth_2->n = top->n + nth_2->n;
			free(nth_2->prev);
			(*stack) = nth_2;
			(*stack)->prev = NULL;
			return;
		}
	}

	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * nop - does nothing
 * @stack: The stack
 * @line_number: Line numbers of .m files
 *
 * Return: void
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;
}

/**
 * sub - subs the top two elements
 * @stack: The stack
 * @line_number: Line numbers of .m files
 *
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *nth_2 = NULL;

	if (top)
	{
		nth_2 = top->next;

		if (nth_2)
		{
			nth_2->n -= top->n;
			free(*stack);
			(*stack) = nth_2;
			(*stack)->prev = NULL;
			return;
		}
	}

	fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
