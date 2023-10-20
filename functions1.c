#include "monty.h"


/**
 * zid_lstack - zid chi node l stack.
 * @new_node: new node
 * @line: rakem dyal ster
 */
void zid_lstack(stack_t **new_node, __attribute__((unused))unsigned int  *line)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * tbe3_stack - zid node khera
 * @stack: Pointer
 * @line_number: rakem ster dyal opcode.
 */
void tbe3_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * jbed_lfokani- zid node
 * @stack: Pointer
 * @line_number: rakem dyal ster opcode
 */
void jbed_lfokani(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		zid_moch(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * tbe3_lfokani - tba3 node lfokaniya dyal stack.
 * @stack: Pointer
 * @line_number: rakem dyal ster dyale opcode.
 */
void tbe3_lfokani(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		zid_moch(6, line_number);
	printf("%d\n", (*stack)->n);
}
