#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


void fteh_dossi(char *file_name);
int kssem_ster(char *buffer_line, int rakem_ster, int mise_neforme);
void kra_fichier(FILE *);
int tol_char(FILE *);
void Lka_fonc(char *, char *, int, int);


stack_t *nod_jdida(int n);
void hyed_nod(void);
void tbe3_stack(stack_t **, unsigned int);
void zid_lstack(stack_t **, unsigned int);
void zid_lssef(stack_t **, unsigned int);

void lgha_lfon(op_func, char *, char *, int, int);

void tbe3_lfokani(stack_t **, unsigned int);
void jbed_lfokani(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void gleb_nodat(stack_t **, unsigned int);


void zid_nodat(stack_t **, unsigned int);
void neks_nodat(stack_t **, unsigned int);
void kssem_nodat(stack_t **, unsigned int);
void dreb_nodat(stack_t **, unsigned int);
void lbaki_nodat(stack_t **, unsigned int);

void tba3_chara(stack_t **, unsigned int);
void tba3_kelmat(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);


void mochkil(int error_code, ...);
void zid_moch(int error_code, ...);
void stream_err(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
