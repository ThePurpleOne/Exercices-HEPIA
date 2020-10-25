/*===========================================================================*
   Auteur   : STIRNEMANN Jonas
   Date création : 29/09/2020
=============================================================================
   Descriptif: lib allowing to create and manage fraction objetcs 
=*===========================================================================*/

#include <stdio.h>
#include <math.h>
#include "fractions.h"

/*---------------------------------------------------------------------------
	printFraction(fraction fr)
	-------------------------------------------------------------------------
	Description	:	Print a fraction in terminal
	Input		:	fraction struct 
	output		:	
*---------------------------------------------------------------------------*/
void printFraction(fraction fr)
{
	printf(" %ld / %ld ", fr.num, fr.den);
}

/*---------------------------------------------------------------------------
	getPGCD(fraction fr)
	-------------------------------------------------------------------------
	Description	:	Get the PGCD of two numbers
	Input		:	long number 1 | long number 2
	output		:	long PGCD
*---------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------
	reductFraction(fraction fr)
	-------------------------------------------------------------------------
	Description	:	get an irreductible version of the fraction
	Input		:	struct fraction
	output		:	struct fraction
*---------------------------------------------------------------------------*/
fraction reductFraction(fraction fr)
{
	fraction tempFr;
	long pgcdFr = getPGCD(fr.den, fr.num); 
	
	tempFr.den = fr.den / pgcdFr; 
	tempFr.num = fr.num / pgcdFr; 
	return tempFr;
}

/*---------------------------------------------------------------------------
	powFr(fraction fr)
	-------------------------------------------------------------------------
	Description	:	return a poweredToNumber irreductible fraction
	Input		:	struct fraction, long power 
	output		:	struct fraction 
*---------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------
	fraction_add(fraction fr1, fraction fr2)
	-------------------------------------------------------------------------
	Description	:	Add and return a fraction
	Input		:	struct fraction, struct fraction 2 
	output		:	struct fraction 
*---------------------------------------------------------------------------*/
fraction fraction_add(fraction fr1, fraction fr2)
{
	fraction returnFr;

	//get the right denominator
	returnFr.den = fr1.den * fr2.den;
	//get the right numerator
	returnFr.num = ( fr1.num * fr2.den ) +  ( fr2.num * fr1.den );

	return( reductFraction(returnFr) );
}

/*---------------------------------------------------------------------------
	fraction_mul()(fraction fr1, fraction fr2)
	-------------------------------------------------------------------------
	Description	:	Multiply and return a fraction
	Input		:	struct fraction, struct fraction 2 
	output		:	struct fraction 
*---------------------------------------------------------------------------*/
fraction fraction_mul(fraction fr1, fraction fr2)
{
	fraction returnFr;

	//get the right numerator
	returnFr.num = fr1.num * fr2.num;
	//get the right denominator
	returnFr.den = fr1.den * fr2.den;

	return( reductFraction(returnFr) );
}

/*---------------------------------------------------------------------------
	fraction_div(fraction fr1, fraction fr2)
	-------------------------------------------------------------------------
	Description	: 	Divide and return a fraction
	Input		:	struct fraction, struct fraction 2
	output		:	struct fraction 
*---------------------------------------------------------------------------*/
fraction fraction_div(fraction fr1, fraction fr2)
{
	fraction returnFr;

	//get the right numerator
	returnFr.num = fr1.num * fr2.den;
	//get the right denominator
	returnFr.den = fr1.den * fr2.num;

	return( reductFraction(returnFr) );
}

/*---------------------------------------------------------------------------
	fraction_sub(fraction fr1, fraction fr2)
	-------------------------------------------------------------------------
	Description	:	substract and return a fraction
	Input		:	struct fraction, struct fraction 2 
	output		:	struct fraction 
*---------------------------------------------------------------------------*/
fraction fraction_sub(fraction fr1, fraction fr2)
{
	fraction returnFr;

	//get the right denominator
	returnFr.den = fr1.den * fr2.den;
	//get the right numerator
	returnFr.num = ( fr1.num * fr2.den ) - ( fr2.num * fr1.den );

	return( reductFraction(returnFr) );
}


/*---------------------------------------------------------------------------
	fraction_to_double(fraction)
	-------------------------------------------------------------------------
	Description	:	get the real result of a fraction object
	Input		:	fraction 
	output		:	double  
*---------------------------------------------------------------------------*/
double fraction_to_double(fraction fr1)
{
	return((double)fr1.num / (double)fr1.den);
}

