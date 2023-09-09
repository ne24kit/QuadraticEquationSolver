#include "math_utils.h"

bool is_zero(const double n)
{
	const double EPS = 1e-6;
	return fabs(n) < EPS;
}

bool is_equal_double(double m, double n)
{
	return is_zero(m - n);
}

bool check_equality(const double n, const double m)
{
	bool is_nan_n = isnan(n);
	bool is_nan_m = isnan(m);

	if (is_nan_n && is_nan_m)
		return true;
	if (is_nan_n || is_nan_m)
		return false;

	return is_zero(m - n);
}

double fix_minus_zero(const double num)
{
	if (is_zero(num))
		return 0.0;
    
	return num;
}

void swap(double *m, double *n)
{
	assert(m != NULL);
	assert(n != NULL);

	double temp = *m;

	*m = *n;
	*n = temp;
}

void sort_two_items(double *m, double *n)
{
	assert(m != NULL);
	assert(n != NULL);

	if (*m > *n)
		swap(m, n);
}