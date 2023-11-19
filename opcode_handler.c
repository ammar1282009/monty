#include "monty.h"

/**
 * opcode_handler - handles the opcodes
 * @opcode: opcode of .m files
 *
 * Return: void
*/
void (*opcode_handler(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
			{"push", push}, {"pall", pall},
			{"pint", pint}, {"pop", pop},
			{"swap", swap}, {"add", add},
			{"nop", nop}, {"sub", sub},
			{"div", _div}, {"mul", mul},
			{"pchar", pchar}, {"pstr", pstr},
			{NULL, NULL},
	};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i].f);
	}

	return (NULL);
}
