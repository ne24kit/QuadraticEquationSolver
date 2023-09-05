#pragma once

#include "qsolver.h"
#include "color_constants.h"

typedef struct{
	EquationCoefficients coefs;
	EquationRoots roots;
}TestCase;

int test_solver();

static void report_failed_test(EquationRoots expect, EquationRoots evaluate, int num);
static void report_result_of_testing(int number);
