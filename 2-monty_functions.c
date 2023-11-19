#include "monty.h"

/**
 * _div - divs the top two elements
 * @stack: The stack
 * @line_number: Line numbers of .m files
 *
 * Return: void
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *nth_2 = NULL;


	if (top)
	{
		nth_2 = top->next;

		if (top->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}

		if (nth_2)
		{
			nth_2->n /= top->n;
			free(*stack);
			(*stack) = nth_2;
			(*stack)->prev = NULL;
			return;
		}
	}

	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * mul - muls the top two elements
 * @stack: The stack
 * @line_number: Line numbers of .m files
 *
 * Return: void
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *nth_2 = NULL;


	if (top)
	{
		nth_2 = top->next;

		if (nth_2)
		{
			nth_2->n *= top->n;
			free(*stack);
			(*stack) = nth_2;
			(*stack)->prev = NULL;
			return;
		}
	}

	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * pchar - pchar elements
 * @stack: The stack
 * @line_number: Line numbers of .m files
 *
 * Return: void
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n >= 32 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - makes a string
 * @stack: The stack
 * @line_number: Line numbers of .m files
 *
 * Return: void
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;
	(void)line_number;

	if (!traverse)
	{
		printf("\n");
		return;
	}

		while (traverse)
		{
			if (traverse->n == 0)
				break;

			if (traverse->n < 1 && traverse->n > 128)
				break;

			printf("%c", traverse->n);
			traverse = traverse->next;
		}

		printf("\n");
}
