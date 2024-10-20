#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @head: head of stack
 * @l_count: line counter
 */
void _push(stack_t **head, unsigned int l_count)
{
	char *arg;
	stack_t *new;

	arg = strtok(NULL, " \n\t");
	if (arg == NULL || !isinteger(arg))
	{
		fprintf(stderr, "L%d: USAGE: push integer\n", l_count);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);

	new->n = atoi(arg);
	new->next = *stack;
	new->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;

}
