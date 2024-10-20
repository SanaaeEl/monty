#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
