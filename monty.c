#include "monty.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: Always success
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	int interpreted = 1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");

	while (interpreted)
	{
		interpreted = interpret_code(fp, &stack, line_number);
		line_number++;
	}
	fclose(fp);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
