#include "monty.h"

/**
 * fteh_dossi - fteh l fichier
 * @smiya_fichier: fin kayne l fichier
 * Return: void
 */

void fteh_dossi(char *smiya_fichier)
{
	FILE *fd = fopen(smiya_fichier, "r");

	if (smiya_fichier == NULL || fd == NULL)
		mochkil(2, smiya_fichier);

	kra_fichier(fd);
	fclose(fd);
}


/**
 * kra_fichier - kra l fichier
 * @fd: pointer to fichier.
 * Return: void
 */

void kra_fichier(FILE *fd)
{
	int rakem_ster, mise_neforme = 0;
	char *buffer_line = NULL;
	size_t len = 0;

	for (rakem_ster = 1; getline(&buffer_line, &len, fd) != -1; rakem_ster++)
	{
		mise_neforme = kssem_ster(buffer_line, rakem_ster, mise_neforme);
	}
	free(buffer_line);
}


/**
 * kssem_ster - kssem ster lkelmat
 * @buffer_line: line men l fichier
 * @rakem_ster: rakem dyal line
 * @mise_neforme:  chi haja rak tema
 * if 1 zid chi haja
 * Return: Returns 0 
 */

int kssem_ster(char *buffer_line, int rakem_ster, int mise_neforme)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer_line == NULL)
		mochkil(4);

	opcode = strtok(buffer_line, delim);
	if (opcode == NULL)
		return (mise_neforme);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	Lka_fonc(opcode, value, rakem_ster, mise_neforme);
	return (mise_neforme);
}

/**
 * Lka_fonc - lka la fonction
 * @opcode: opcode
 * @value: argument of opcode
 * @mise_neforme:  storage mise_neforme. 
 * @ln: rakem dyal ster 
 * Return: void
 */
void Lka_fonc(char *opcode, char *value, int ln, int mise_neforme)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", zid_lstack},
		{"pall", tbe3_stack},
		{"pint", tbe3_lfokani},
		{"pop", jbed_lfokani},
		{"nop", nop},
		{"swap", gleb_nodat},
		{"add", zid_nodat},
		{"sub", neks_nodat},
		{"div", kssem_nodat},
		{"mul", dreb_nodat},
		{"mod", lbaki_nodat},
		{"pchar", tba3_chara},
		{"pstr", tba3_kelmat},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			lgha_lfon(func_list[i].f, opcode, value, ln, mise_neforme);
			flag = 0;
		}
	}
	if (flag == 1)
		mochkil(3, ln, opcode);
}


/**
 * lgha_lfon - lgha la fonction.
 * @func: Pointer to the function 
 * @op: string of the opcode.
 * @val: string tha represnts a numeric value.
 * @ln: rakem ster
 * @mise_neforme: mise_neforme specifier. 
 * chi haja rak tema.
 */
void lgha_lfon(op_func func, char *op, char *val, int ln, int mise_neforme)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			mochkil(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				mochkil(5, ln);
		}
		node = nod_jdida(atoi(val) * flag);
		if (mise_neforme == 0)
			func(&node, ln);
		if (mise_neforme == 1)
			zid_lssef(&node, ln);
	}
	else
		func(&head, ln);
}
