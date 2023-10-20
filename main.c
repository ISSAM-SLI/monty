#include "monty.h"
stack_t *head = NULL;

/**
 * main - The program's entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: Always returns 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fteh_dossi(argv[1]);
	hyed_nod();
	return (0);
}

/**
 * nod_jdida - Generating a new node.
 * @n: Value to be placed inside the node.
 * Return: Returning a pointer.
 */
stack_t *nod_jdida(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		mochkil(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * hyed_nod - Releases memory associated with nodes in the stack.
 */
void hyed_nod(void)
{
	stack_t *val;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		val = head;
		head = head->next;
		free(val);
	}
}

/**
 * zid_lssef - Appending a node to the queue.
 * @nod_jdida: Pointer to the new node.
 * @a: Line of the opcode.
 */
void zid_lssef(stack_t **nod_jdida, __attribute__((unused))unsigned int a)
{
	stack_t *val;

	if (nod_jdida == NULL || *nod_jdida == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nod_jdida;
		return;
	}
	val = head;
	while (val->next != NULL)
		val = val->next;

	val->next = *nod_jdida;
	(*nod_jdida)->prev = val;
}
