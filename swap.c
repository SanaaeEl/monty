#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @head: head of the stack
 * @l_count: lines' count
 */

void _swap(stack_t **head, unsigned int l_count)
{
	stack_t *temp;
	int nm, count = 0;

	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_count);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	nm = temp->n;
	temp->n = temp->next->n;
	temp->next->n = nm;
}
