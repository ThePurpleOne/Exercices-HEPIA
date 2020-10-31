#ifndef _FRACTIONS_H_
#define _FRACTIONS_H_


//http://malaspinas.academy/

//############## END GLOBALS AND STRUCTS ##############
typedef struct 
{
	long num; //numerator
	long den; //denominateur
}fraction;
//############## END GLOBALS AND STRUCTS ##############


//############## FONCTIONS PROTOTYPES ##############
void printFraction(fraction );
long getPGCD(long , long );
fraction reductFraction(fraction );
fraction powFr(fraction , long );
fraction fraction_add(fraction, fraction);
fraction fraction_mul(fraction, fraction);
fraction fraction_div(fraction, fraction);
fraction fraction_sub(fraction, fraction);
double fraction_to_double(fraction);
//############## END FONCTIONS PROTOTYPES ##############

#endif
