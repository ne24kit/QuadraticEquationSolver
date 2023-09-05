#pragma once

#include <stdio.h>
#include "math_utils.h"
#include <assert.h>

/* TODO: K&R + google preprocessor directives and reflexion in defines.  */
// #define concat(a,b) a##b

typedef struct{
	double a = NAN;
	double b = NAN; 
	double c = NAN;
}EquationCoefficients;

typedef struct{
	double x1 = NAN; 
	double x2 = NAN;
}EquationRoots;

enum num_roots {
	NO_ROOTS,
	ONE,
	TWO,
	INF
};

void check_coefs(EquationCoefficients coefs);

num_roots solve_equation(EquationCoefficients coefs, EquationRoots *roots);
num_roots solve_linear_eq(const double b, const double c, double *x1);
num_roots solve_quadratic_eq(EquationCoefficients coefs, EquationRoots *roots);
