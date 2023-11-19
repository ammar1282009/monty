#include "monty.h"

/**
 * interpret_code - interprets the code
 * @fp: pointer to the file descriptor
 * @stack: The stack
 * @line_number: Number of lines in monty files
 *
 * Return: 1 OTHERWISE 0
 */
int interpret_code(FILE *fp, stack_t **stack, unsigned int line_number)
{
	char *line = NULL;
	size_t line_size = 0;
	char *opcode;
	void (*instruction)(stack_t **stack, unsigned int line_number);

	if (getline(&line, &line_size, fp) == -1)
	{
		free(line);
		return (0);
	}

	opcode = strtok(line, " \n");

	if (!opcode)
	{
		free(line);
		return (1);
	}

	if (opcode[0] == '#')
	{
		free(line);
		return (1);
	}

	instruction = opcode_handler(opcode);
	if (!instruction)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		fclose(fp);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	instruction(stack, line_number);
	free(line);
	return (1);
}
