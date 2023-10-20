#include "monty.h"

/**
 * dreb_nodat - dreb chi f chi
 * @stack: Pointer
 * @line_number: rakem dyal ster
 */
void dreb_nodat(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		zid_moch(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * lbaki_nodat - lbaki dyal nodat
 * @stack: Pointer
 * @line_number: rakem dyal ster
 */
void lbaki_nodat(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		zid_moch(8, line_number, "mod");


	if ((*stack)->n == 0)
		zid_moch(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
