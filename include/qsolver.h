#pragma once

#include <stdio.h>
#include "math_utils.h"
#include <assert.h>

typedef struct{
	double a = NAN;
	double b = NAN; 
	double c = NAN;
}EquationCoefficients;

typedef struct{
	double x1 = NAN; 
	double x2 = NAN;
}EquationRoots;

enum Num_roots {
	NO_ROOTS,
	ONE,
	TWO,
	INF
};

void check_coefs(EquationCoefficients *coefs);

Num_roots solve_equation(EquationCoefficients *coefs, EquationRoots *roots);
Num_roots solve_linear_eq(const double b, const double c, double *x1);
Num_roots solve_quadratic_eq(EquationCoefficients *coefs, EquationRoots *roots);
