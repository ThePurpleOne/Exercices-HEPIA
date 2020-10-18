#include <stdio.h>
#include <math.h>
#include "fractions.h"

int main(int argc, char const *argv[])
{
	fraction fr1;
	double pi;

	
	for (long n = 1; n < 999999; n++)
	{
		fr1.num = pow( (-1), (n+1));
		fr1.den = n * n;
		pi += fraction_to_double(fr1);
	}
	
	printf("Pi = %lf\n", sqrt(pi*12));

	return 0;
}

