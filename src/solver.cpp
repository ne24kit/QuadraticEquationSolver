#include "qsolver.h"

// TODO: documentation using doxygen.

void check_coefs(EquationCoefficients coefs)
{
	assert(isfinite(coefs.a) && "'a' is not finite");
	assert(isfinite(coefs.b) && "'b' is not finite");
	assert(isfinite(coefs.c) && "'c' is not finite");		
}

num_roots solve_equation(EquationCoefficients coefs, EquationRoots *roots)
{	
	check_coefs(coefs);

	if (is_zero(coefs.a))
		return solve_linear_eq(coefs.b, coefs.c, &roots->x1);

	return solve_quadratic_eq(coefs, roots);
}

num_roots solve_linear_eq(const double b, const double c, double *x1)
{
	if (is_zero(b)){
		if (is_zero(c))
			return INF;
		return NO_ROOTS;
	}

	*x1 = fix_minus_zero(-c / b);

	return ONE;
}

num_roots solve_quadratic_eq(EquationCoefficients coefs, EquationRoots *roots)
{
	double d = coefs.b * coefs.b - 4 * coefs.a * coefs.c;

	if (is_zero(d)){
		roots->x1 = fix_minus_zero(-coefs.b / (2 * coefs.a));
		return ONE;
	}else if (d > 0){
		roots->x1 = fix_minus_zero((-coefs.b - sqrt(d)) / (2 * coefs.a));
		roots->x2 = fix_minus_zero((-coefs.b + sqrt(d)) / (2 * coefs.a));
		sort_two_items(&roots->x1, &roots->x2);
		return TWO;
	}

	return NO_ROOTS;
}
