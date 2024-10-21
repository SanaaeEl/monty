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
	char *endptr;
	long value;

	arg = strtok(NULL, " \n\t");
	if (arg == NULL || *arg == '\0')
	{
		fprintf(stderr, "L%d: USAGE: push integer\n", l_count);
		exit(EXIT_FAILURE);
	}

	value = strtol(arg, &endptr, 10);
	if (*endptr != '\0' || endptr == arg)
	{
		fprintf(stderr, "L%d: USAGE push integer\n", l_count);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = (int)value;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;

}
