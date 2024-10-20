#include "monty.h"

/**
 * main - monty enterpreter
 * @argc: arguments' count
 * @argv: list of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	char *line;
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

	while ((line = getline(&line, &len, file)) != NULL)
	{
		instruction = get_instruction(line);
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
