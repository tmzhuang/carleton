/* lab5.c - SYSC 2006 Fall 2012 Lab 5 */
#include <stdio.h>
#include "fraction.h"


int main(void)
{
	struct fraction fr;

	/* Test print_fraction. */
	printf("\nTesting print_fraction.\n");

	fr.num = 1;
	fr.den = 3;
	printf("Calling print_fraction to print 1/3. Actual result = ");
	print_fraction(fr);
	printf(".\n");

	fr.num = -1;
	fr.den = 3;
	printf("Calling print_fraction to print -1/3. Actual result = ");
	print_fraction(fr);
	printf(".\n");

	/* Test gcd. */
	printf("\nTesting gcd.\n");

	if (gcd(42,30) != 6)
		printf("Calling gcd(42, 30). Expected result = 6. Actual result = %d.\n",
		    gcd(42, 30));

	if (gcd(30,42) != 6)
		printf("Calling gcd(30, 42). Expected result = 6. Actual result = %d.\n",
		    gcd(30, 42));

	if (gcd(-42,30) != 6)
		printf("Calling gcd(-42, 30). Expected result = 6. Actual result = %d.\n",
		    gcd(-42, 30));

	if (gcd(42,-30) != 6)
		printf("Calling gcd(42, -30). Expected result = 6. Actual result = %d.\n",
		    gcd(42, -30));

	if (gcd(-42,-30) != 6)
		printf("Calling gcd(-42, -30). Expected result = 6. Actual result = %d.\n",
		    gcd(-42, -30));

	if (gcd(144,55) != 1)
		printf("Calling gcd(144, 55). Expected result = 1. Actual result = %d.\n",
		    gcd(144, 55));

	/* Test reduce. */
	printf("\nTesting reduce.\n");

	fr.num = 1;
	fr.den = 3;
	printf("Reduce 1/3. Expected result = 1/3. Actual result = ");
	print_fraction(reduce(fr));
	printf(".\n");

	fr.num = 6;
	fr.den = 8;
	printf("Reduce 6/8. Expected result = 3/4. Actual result = ");
	print_fraction(reduce(fr));
	printf(".\n");

	fr.num = -2;
	fr.den = 3;
	printf("Reduce -2/3. Expected result = -2/3. Actual result = ");
	print_fraction(reduce(fr));
	printf(".\n");

	fr.num = 4;
	fr.den = -5;
	printf("Reduce 4/-5. Expected result = -4/5. Actual result = ");
	print_fraction(reduce(fr));
	printf(".\n");

	fr.num = -6;
	fr.den = -8;
	printf("Reduce -6/-8. Expected result = 3/4. Actual result = ");
	print_fraction(reduce(fr));
	printf(".\n");

	fr.num = 0;
	fr.den = 7;
	printf("Reduce 0/7. Expected result = 0/1. Actual result = ");
	print_fraction(reduce(fr));
	printf(".\n");

	/* Test make_fraction. */
	printf("\nTesting make_fraction.\n");

	struct fraction result;
	
	result = make_fraction(1,3);
	if (result.num != 1 || result.den != 3) {
		printf("Calling make_fraction(1, 3). Expected result = 1/3. Actual result = ");
		print_fraction(make_fraction(1, 3));
		printf(".\n");
	}

	result = make_fraction(6,8);
	if (result.num != 3 || result.den != 4) {
		printf("Calling make_fraction(6, 8). Expected result = 3/4. Actual result = ");
		print_fraction(make_fraction(6, 8));
		printf(".\n");
	}

	result = make_fraction(-2,3);
	if (result.num != -2 || result.den != 3) {
		printf("Calling make_fraction(-2, 3). Expected result = -2/3. Actual result = ");
		print_fraction(make_fraction(-2, 3));
		printf(".\n");
	}

	result = make_fraction(4,-5);
	if (result.num != -4 || result.den != 5) {
		printf("Calling make_fraction(4, -5). Expected result = -4/5. Actual result = ");
		print_fraction(make_fraction(4, -5));
		printf(".\n");
	}

	result = make_fraction(-6,-8);
	if (result.num != 3 || result.den != 4) {
		printf("Calling make_fraction(-6, -8). Expected result = 3/4. Actual result = ");
		print_fraction(make_fraction(-6, -8));
		printf(".\n");
	}

	result = make_fraction(0,7);
	if (result.num != 0 || result.den != 1) {
		printf("Calling make_fraction(0, 7). Expected result = 0/1. Actual result = ");
		print_fraction(make_fraction(0, 7));
		printf(".\n");
	}

	/* Test multiply_fractions. */
	printf("\nTesting multiply_fractions.\n");
	result = multiply_fractions(make_fraction(0,1), make_fraction(0,2));
	if (result.num != 0 || result.den != 1) {
		printf("Calling multiply_fractions(make_fraction(0,1), make_fraction(0,2)). Expected result = 0/1. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}

	result = multiply_fractions(make_fraction(1,1), make_fraction(0,2));
	if (result.num != 0 || result.den != 1) {
		printf("Calling multiply_fractions(make_fraction(1,1), make_fraction(0,2)). Expected result = 0/1. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}

	result = multiply_fractions(make_fraction(0,1), make_fraction(2,2));
	if (result.num != 0 || result.den != 1) {
		printf("Calling multiply_fractions(make_fraction(0,1), make_fraction(2,2)). Expected result = 0/1. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}

	result = multiply_fractions(make_fraction(3,1), make_fraction(4,2));
	if (result.num != 6 || result.den != 1) {
		printf("Calling multiply_fractions(make_fraction(3,1), make_fraction(4,2)). Expected result = 6/1. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}

	result = multiply_fractions(make_fraction(3,2), make_fraction(2,9));
	if (result.num != 1 || result.den != 3) {
		printf("Calling multiply_fractions(make_fraction(3,2), make_fraction(2,9)). Expected result = 1/3. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}

	result = multiply_fractions(make_fraction(3,12), make_fraction(4,9));
	if (result.num != 1 || result.den != 9) {
		printf("Calling multiply_fractions(make_fraction(3,12), make_fraction(4,9)). Expected result = 1/1. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}


	/* Test add_fractions. */
	printf("\nTesting add_fractions.\n");

	result = add_fractions(make_fraction(0,1), make_fraction(0,2));
	if (result.num != 0 || result.den != 1) {
		printf("Calling add_fractions(make_fraction(0,1), make_fraction(0,2)). Expected result = 0/1. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}

	result = add_fractions(make_fraction(1,1), make_fraction(0,2));
	if (result.num != 1 || result.den != 1) {
		printf("Calling add_fractions(make_fraction(1,1), make_fraction(0,2)). Expected result = 1/1. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}

	result = add_fractions(make_fraction(0,1), make_fraction(2,2));
	if (result.num != 1 || result.den != 1) {
		printf("Calling add_fractions(make_fraction(0,1), make_fraction(2,2)). Expected result = 1/1. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}

	result = add_fractions(make_fraction(3,1), make_fraction(4,2));
	if (result.num != 5 || result.den != 1) {
		printf("Calling add_fractions(make_fraction(3,1), make_fraction(4,2)). Expected result = 5/1. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}

	result = add_fractions(make_fraction(3,2), make_fraction(2,9));
	if (result.num != 31 || result.den != 18) {
		printf("Calling add_fractions(make_fraction(3,2), make_fraction(2,9)). Expected result = 31/18. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}

	result = add_fractions(make_fraction(3,12), make_fraction(4,9));
	if (result.num != 25 || result.den != 36) {
		printf("Calling add_fractions(make_fraction(3,12), make_fraction(4,9)). Expected result = 25/36. Actual result = ");
		print_fraction(result);
		printf(".\n");
	}



	return 0;
}



