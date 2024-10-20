#include "monty.h"

/**
 * _pall - prints all the elements on the stack, starting from the top
 * @stack: head of the stack
 */
void _pall(stack_t **stack, unsigned int l_count)
{
	(void)l_count;
	stack_t *current;

	*current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
