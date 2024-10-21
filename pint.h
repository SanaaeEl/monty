#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @head: head of the stack
 * @l_count: lines' count
 */
void _pint(stack_t **head, unsigned int l_count)
{
	(void)l_count;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l_count);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
