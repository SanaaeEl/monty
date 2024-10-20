#include "monty.h"

/**
 *
 */
int get_instruction(char *line, stack_t *stack, unsigned int counter, FILE *file)
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
		return (0);

	for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			instructions[i].f(stack, counter);
	}

	if (opcode && instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter,
				opcode);
		fclose(file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);

}
