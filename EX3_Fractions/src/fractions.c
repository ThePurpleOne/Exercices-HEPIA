/*===========================================================================*
   Auteur   : STIRNEMANN Jonas
   Date création : 29/09/2020
=============================================================================
   Descriptif: lib allowing to create and manage fraction objetcs 
=*===========================================================================*/

#include <stdio.h>
#include <math.h>
#include "../headers/fractions.h"

/// Print a fraction in terminal
/// @param fr Fraction to print
void printFraction(fraction fr)
{
	printf(" %ld / %ld ", fr.num, fr.den);
}

/// Return the PGCD of two numbers
/// @param nb1 First number
/// @param nb2 Second number
/// @return pgcd
long getPGCD(long nb1, long nb2)
{
	long x = nb1, y = nb2, rst;

	while(y != 0)
	{
		rst = x % y;
		x = y;
		y = rst;
	}
	return x;
}


/// Return an irreductible version of the fraction
/// @param fr Fraction to reduce
/// @return reduced fraction 
fraction reductFraction(fraction fr)
{
	fraction tempFr;
	long pgcdFr = getPGCD(fr.den, fr.num); 
	
	tempFr.den = fr.den / pgcdFr; 
	tempFr.num = fr.num / pgcdFr; 
	return tempFr;
}

/// Return a poweredToNumber irreductible fraction
/// @param fr Fraction to power
/// @param power Power to power to
/// @return powered fraction 
fraction powFr(fraction fr, long power)
{
	fraction tempFr = fr;
	long temp;

	if (power < 0)
	{
		// 1 / (2 / 4)^4 = 4^4 / 2^4
		temp = pow(fr.num, power * -1);
		tempFr.num = pow(fr.den, power * -1);
		tempFr.den = temp;
	}
	else
	{
		tempFr.num = pow(fr.num, power);
		tempFr.den = pow(fr.den, power);
	}
	
	return reductFraction(tempFr);
}

/// Add and return a fraction
/// @param fr1 First fraction
/// @param fr2 Second fraction
/// @return added fractions
fraction fraction_add(fraction fr1, fraction fr2)
{
	fraction returnFr;

	//get the right denominator
	returnFr.den = fr1.den * fr2.den;
	//get the right numerator
	returnFr.num = ( fr1.num * fr2.den ) +  ( fr2.num * fr1.den );

	return( reductFraction(returnFr) );
}

/// Return multiplied fractions
/// @param fr1 First fraction
/// @param fr2 Second fraction
/// @return added fractions
fraction fraction_mul(fraction fr1, fraction fr2)
{
	fraction returnFr;

	//get the right numerator
	returnFr.num = fr1.num * fr2.num;
	//get the right denominator
	returnFr.den = fr1.den * fr2.den;

	return( reductFraction(returnFr) );
}

///  Return divided fractions
/// @param fr1 First fraction
/// @param fr2 Second fraction
/// @return divided fractions
fraction fraction_div(fraction fr1, fraction fr2)
{
	fraction returnFr;

	//get the right numerator
	returnFr.num = fr1.num * fr2.den;
	//get the right denominator
	returnFr.den = fr1.den * fr2.num;

	return( reductFraction(returnFr) );
}


///  Return substracted fractions
/// @param fr1 First fraction
/// @param fr2 Second fraction
/// @return substracted fractions
fraction fraction_sub(fraction fr1, fraction fr2)
{
	fraction returnFr;

	//get the right denominator
	returnFr.den = fr1.den * fr2.den;
	//get the right numerator
	returnFr.num = ( fr1.num * fr2.den ) - ( fr2.num * fr1.den );

	return( reductFraction(returnFr) );
}


///  Return the result of a fraction
/// @param fr1 First fraction
/// @return A calculated double of the fraction
double fraction_to_double(fraction fr1)
{
	return((double)fr1.num / (double)fr1.den);
}

