#pragma once

#include <math.h>
#include <assert.h>

bool is_zero(const double n);
bool is_equal_double(const double m, const double n);
bool check_equality(const double n, const double m);

double fix_minus_zero(const double n);

void swap(double *m, double *n);
void sort_two_items(double *m,  double *n);