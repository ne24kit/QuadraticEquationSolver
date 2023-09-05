#include "qsolver.h"

static void scan_coef(EquationCoefficients *coefs);
static void print_sol(num_roots count, EquationRoots roots);

/* TODO: spaces + trailing whitespaces.  */

int main()
{
	EquationCoefficients coefs;
	EquationRoots roots;
	scan_coef(&coefs);
	print_sol(solve_equation(coefs, &roots), roots);

	return 0;
}

static void scan_coef(EquationCoefficients *coefs)
{
	printf("Enter the coefficients 'a', 'b', 'c' of the quadratic equation a * x^2 + b * x + c = 0:\n");

	while(scanf("%lf %lf %lf", &coefs->a, &coefs->b, &coefs->c) != 3){
		while(getchar() != '\n');

		printf("Incorrect coefficient input\n");
		printf("Enter the coefficients as rational number\n");
	}
}

static void print_sol(num_roots count, EquationRoots roots)
{
	switch (count){
		case NO_ROOTS:
			printf("no roots =(\n");
			break;
		case ONE:
			printf("x = %g\n", roots.x1);
			break;
		case TWO:
			printf("x1 = %g, x2 = %g\n", roots.x1, roots.x2);
			break;
		case INF:
			printf("infinite roots\n");
			break;
		default:
			printf("root count error");
	}
}
