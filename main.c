#include "monty.h"

/**
 * main - monty enterpreter
 * @argc: arguments' count
 * @argv: list of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *line;
	FILE *file;
	stack_t *stack = NULL;
	ssize_t line_number = 1;
	instruction_t *instruction;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: could not open file %s\n",
				argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((line = getline(&line, &line_number, file)) != NULL)
	{
		instruction = get_instruct(line, stack, line_number, file);
		if (instruction == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction\n",
					line_number);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	
		instruction->f(&stack, line_number);
		line_number++;
	}

	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
