#include "monty.h"

/**
 * get_instruct - fetches the coresponding function
 * @line: line content
 * @stack: head of the stack
 * @count: line count
 * @file: monty file
 * Return: 0 on success
 */
int get_instruct(char *line, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t instructions[] = {
		{"push", _push},
		/**
		* {"pall", _pall},
		*/
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode = strtok(line, " \n");

	if (opcode == NULL)
		return (1);

	for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, count);
			return (0);
		}
	}

	if (opcode && instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count,
				opcode);
		fclose(file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);

}
