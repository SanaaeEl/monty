#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @head: head of the stack
 * @l_count: lines' count
 */

void _add(stack_t **head, unsigned int l_count)
{
	stack_t *temp;
	int count = 0;

	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_count);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	temp->next->n += temp->n;
	*head = temp->next;
	free(temp);
}
