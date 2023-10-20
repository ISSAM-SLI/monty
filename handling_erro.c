#include "monty.h"

/**
 * mochkil - Printing ila kan chi error.
 * @chi_erreur: les erreur homa hado:
 * (1) => ima ye3tih fichier wheda wla may3tihach ga3.
 * (2) => le fichier maymkench tefte7.
 * (3) => l fichier fiha des instructions fausses.
 * (4) => mli l programme may9derch y alloci.
 * (5) => ila les parameteres machi int.
 * (6) => ila kan stack khawi bach tprinti.
 * (7) => ila kan stack khawi bach tpopi.
 * (8) => ila stack sghir bezafe.
 */
void mochkil(int chi_erreur, ...)
{
	va_list bda;
	char *la;
	int chi_rakm;

	va_start(bda, chi_erreur);
	switch (chi_erreur)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(bda, char *));
			break;
		case 3:
			chi_rakm = va_arg(bda, int);
			la = va_arg(bda, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", chi_rakm, la);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(bda, int));
			break;
		default:
			break;
	}
	hyed_nod();
	exit(EXIT_FAILURE);
}

/**
 * zid_moch - supporti les erreurs.
 * @chi_erreur: les erruers homa hado:
 * (6) => ila kan stack khawi.
 * (7) => ila kan stack khawi bach tkhorj.
 * (8) => ila kan stack khawi pour les operation.
 * (9) => tkssem 3la 0.
 */
void zid_moch(int chi_erreur, ...)
{
	va_list bda;
	char *la;
	int chi_rakm;

	va_start(bda, chi_erreur);
	switch (chi_erreur)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(bda, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(bda, int));
			break;
		case 8:
			chi_rakm = va_arg(bda, unsigned int);
			la = va_arg(bda, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", chi_rakm, la);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(bda, unsigned int));
			break;
		default:
			break;
	}
	hyed_nod();
	exit(EXIT_FAILURE);
}

/**
 * chaîne_err - supporti les erreurs.
 * @chi_erreur: les erreurs homa hado:
 * (10) ~> rakem li f node machi f les limits dyal ASCII .
 * (11) ~> stack khawi.
 */
void chaîne_err(int chi_erreur, ...)
{
	va_list bda;
	int chi_rakm;

	va_start(bda, chi_erreur);
	chi_rakm = va_arg(bda, int);
	switch (chi_erreur)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", chi_rakm);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", chi_rakm);
			break;
		default:
			break;
	}
	hyed_nod();
	exit(EXIT_FAILURE);
}
