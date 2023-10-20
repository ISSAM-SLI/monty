#include "monty.h"

/**
 * tba3_chara -  Ascii value.
 * @stack: Pointer
 * @line_number: rakem dyal ster
 */
void tba3_chara(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		stream_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		stream_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * tba3_kelmat - tbaa lkelmat.
 * @stack: Pointer
 * @ln: rakem dyal ster
 */
void tba3_kelmat(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - dwer chi f chi
 * @stack: Pointer
 * @ln: rakem dyal ster
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - dwer chi f chi
 * @stack: Pointer
 * @ln: rakem dyal ster
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
