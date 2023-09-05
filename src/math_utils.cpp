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
	if (isnan(n) && isnan(m))
		return true;
	if (isnan(n) || isnan(m))
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

//TODO: rename
void sort_two_items(double *m, double *n)
{
	assert(m != NULL);
	assert(n != NULL);

	if (*m > *n)
		swap(m, n);
}