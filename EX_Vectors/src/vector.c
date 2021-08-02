/*
	* CODE VECTOR
	* Author : Jonas S.
	* Date   : 07/21/2021
	! DESCRIPTION
*/
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"



/*
	* DESCRIPTION : INIT VECTOR  

	? INPUTS : [vector] *v 
	? OUTPUT : [void]
*/
void vector_init(vector *v) 
{
	v->capacity = VECTOR_INIT_CAPACITY;
	v->length = 0;
	v->content = malloc(VECTOR_INIT_CAPACITY * sizeof(type));
}

/*
	* DESCRIPTION : Set the lenght of the vector  

	? INPUTS : [vector] *v 
	? OUTPUT : [void]
*/
void vector_length(vector *v, int *length)
{
	v->length = *length;
}

