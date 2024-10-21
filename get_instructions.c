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
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode = strtok(line, " \n");

	if (opcode == NULL)
		return (1);

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, count);
			return (0);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
	fclose(file);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	return (1);

}

/**
 * read_line - behaves similarly to getline()
 * @lineptr: buffer where the read line will be stored
 * @n: size of buffer
 * @stream: file to read
 * Return: number of characters read
 */
ssize_t read_line(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer;
	size_t len = 0;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	buffer = *lineptr;

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (len + 1 >= *n)
		{
			*n *= 2;
			buffer = realloc(buffer, *n);
			if (buffer == NULL)
				return (-1);
			*lineptr = buffer;
		}
		buffer[len++] = (char)c;
	}

	if (len == 0 && c == EOF)
		return (-1);

	buffer[len] = '\0';
	return ((ssize_t)len);
}
