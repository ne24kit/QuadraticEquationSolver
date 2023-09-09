#include "test.h"

int main()
{
	report_result_of_testing(test_solver());

	return 0;
}

int test_solver()
{
	TestCase tests[] = {
		{{  1,   2,   1}, { -1, NAN}},
		{{  1,   0,  -1}, { -1,   1}},
		{{  0,   0,   0}, {NAN, NAN}},
		{{  1,   1,   1}, {NAN, NAN}},
		{{  0,   1,   0}, {  0, NAN}},
		{{  1,  12,  11}, {-11,  -1}},
		{{  1,   0,   0}, {  0, NAN}},
		{{  1,   0,  -9}, { -3,   3}},
		{{  1,   6,   8}, { -4,  -2}}
	};

	int size = sizeof(tests) / sizeof(tests[0]);
	int corr_test = 0;

	for(int i = 0; i < size; ++i){
		EquationRoots program_roots;

		solve_equation(&tests[i].coefs, &program_roots);
		
		if (check_equality(program_roots.x1, tests[i].roots.x1) &&
				check_equality(program_roots.x2, tests[i].roots.x2))
			corr_test++;
		else
			report_failed_test(tests[i].roots, program_roots, i);
	}

	return size - corr_test;
}

static void report_failed_test(EquationRoots expect, EquationRoots evaluate, int num)
{
	printf("---------\n");
	printf("Number  of  test: %3d\n", num);
	printf("Expected    answer: %3g %3g\n", expect.x1, expect.x2);
	printf("Evaluated   answer: %3g %3g\n", evaluate.x1, evaluate.x2);
	printf("---------\n");
}

static void report_result_of_testing(int number)
{
	if (number){
		PRINT_COLORFUL_STRING("Number of failed tests:", ANSI_COLOR_RED);
		printf("%3d\n", number);
	}else
		PRINT_COLORFUL_STRING("All tests were successful\n", ANSI_COLOR_GREEN);
}
