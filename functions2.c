#include "monty.h"

/**
 * nop - madir walo.
 * @stack: Pointer .
 * @line_number: rakem dyal ster.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * gleb_nodat - gleb joj arkam
 * @stack: Pointer
 * @line_number: rakem dyal ster
 */
void gleb_nodat(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		zid_moch(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * zid_nodat - zid joj arkam l stack
 * @stack: Pointer
 * @line_number: rakem dyals ster
 */
void zid_nodat(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		zid_moch(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * neks_nodat - zid joj arkam
 * @stack: Pointer
 * @line_number: rakem dyal ster
 */
void neks_nodat(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		zid_moch(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * kssem_nodat - zid joj arkam
 * @stack: Pointer
 * @line_number: rakem dyal ster
 */
void kssem_nodat(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		zid_moch(8, line_number, "div");

	if ((*stack)->n == 0)
		zid_moch(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
