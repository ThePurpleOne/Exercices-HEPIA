#include <stdio.h>
#include <math.h>
#include "fractions.h"

int main(int argc, char const *argv[])
{
	fraction fr1;
	fraction frBuffer;
	fr1.num = 1;
	fr1.den = 1;
	frBuffer.num = 1;
	frBuffer.den = 1;
	printf("%ld", fraction_to_double(fr1));

	
	for (long n = 2; n < 100; n++)
	{
		frBuffer.num = pow( (1), (n+1));
		frBuffer.den = pow(n, 2);
		printFraction(frBuffer);
		printf("\n");
		fr1 = fraction_mul(fr1, frBuffer);
	}
	
	frBuffer.num = 12;
	frBuffer.den = 1;
	fr1 = fraction_mul(fr1, frBuffer);

	printf("%ld", fraction_to_double(fr1));

	return 0;
}

