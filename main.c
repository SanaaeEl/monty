#include "monty.h"

/**
 * main - monty enterpreter
 * @argc: arguments' count
 * @argv: list of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *line = NULL;
	FILE *file;
	stack_t *stack = NULL;
	ssize_t read;
	unsigned int line_number = 1;
	size_t len = 0;

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

	while ((read = read_line(&line, &len, file)) != -1)
	{
		get_instruct(line, &stack, line_number, file);
		line_number++;
	}

	fclose(file);
	free(line);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
