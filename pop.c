#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: head of the stack
 * @l_count: lines' count
 */
void _pop(stack_t **head, unsigned int l_count)
{
	(void)l_count;
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", l_count);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
