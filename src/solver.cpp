#include "qsolver.h"

// TODO: documentation using doxygen.

void check_coefs(EquationCoefficients *coefs)
{
	assert(isfinite(coefs->a) && "'a' is not finite");
	assert(isfinite(coefs->b) && "'b' is not finite");
	assert(isfinite(coefs->c) && "'c' is not finite");		
}

Num_roots solve_equation(EquationCoefficients *coefs, EquationRoots *roots)
{	
	check_coefs(coefs);

	if (is_zero(coefs->a))
		return solve_linear_eq(coefs->b, coefs->c, &roots->x1);

	return solve_quadratic_eq(coefs, roots);
}

Num_roots solve_linear_eq(const double b, const double c, double *x1)
{
	if (is_zero(b)){
		if (is_zero(c))
			return INF;
		return NO_ROOTS;
	}

	*x1 = fix_minus_zero(-c / b);

	return ONE;
}

Num_roots solve_quadratic_eq(EquationCoefficients *coefs, EquationRoots *roots)
{
	check_coefs(coefs);

	double d = coefs->b * coefs->b - 4 * coefs->a * coefs->c;
	double twice_a = 2 * coefs->a;

	if (is_zero(d)){
		roots->x1 = fix_minus_zero(-coefs->b / twice_a);
		return ONE;

	}else if (d > 0){
		double sqrt_d = sqrt(d);
		
		roots->x1 = fix_minus_zero((-coefs->b - sqrt_d) / twice_a);
		roots->x2 = fix_minus_zero((-coefs->b + sqrt_d) / twice_a);
		
		sort_two_items(&roots->x1, &roots->x2);
		return TWO;
	}

	return NO_ROOTS;
}
