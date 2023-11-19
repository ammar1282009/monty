#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
/**
 * push - pushing element to the stack
 * @stack: The stack
 * @line_number: Line numbers of .m files
 *
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	int i;
	int num;
	stack_t *new = NULL;

	char *arg = strtok(NULL, " \n");

	if (!arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; arg[i]; i++)
	{
		if (!isdigit(arg[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	num = atoi(arg);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free_stack(*stack);
		fprintf(fp, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = num;

	if (stack)
	{
		new->next = *stack;
		if (*stack)
			(*stack)->prev = new;

		*stack = new;
	}
	else
	{
		new->next = NULL;
	}
}

/**
 * pall - prints the stack
 * @stack: The stack
 * @line_number: line number of .m files
 *
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;

	(void)line_number;

	if (!*stack)
		return;

	while (traverse)
	{
		printf("%d\n", traverse->n);
		traverse = traverse->next;
	}
}

/**
 * pint - prints the top element of the stack
 * @stack: The stack
 * @line_number: line number of .m files
 *
 * Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Deletes the top element of the stack
 * @stack: The stack
 * @line_number: Line number of .m files
 *
 * Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;

	free(temp);
}
