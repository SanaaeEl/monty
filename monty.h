#ifndef _MONTY_H_
#define _MONTY_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Desription: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Descripton: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void _push(stack_t **head, unsigned int l_count);
void _pall(stack_t **stack, unsigned int l_count);
void _pint(stack_t **head, unsigned int l_count);
void _pop(stack_t **head, unsigned int l_count);
void _swap(stack_t **head, unsigned int l_count);
void _add(stack_t **head, unsigned int l_count);
void _nop(stack_t **head, unsigned int l_count);

int get_instruct(char *line, stack_t **stack, unsigned int count, FILE *file);
void free_stack(stack_t *stack);
ssize_t read_line(char **lineptr, size_t *n, FILE *stream);





#endif  /** _MONTY_H_ */
