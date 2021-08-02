/*
	* HEADER VECTOR
	* Author : Jonas S.
	* Date   : 07/21/2021
	! DESCRIPTION
	! SOURCE : https://malaspinas.academy/prog_seq_c_tp/vector/index.html
*/

#ifndef _VECTOR_H_
#define _VECTOR_H_

// DEFINES
#define VECTOR_INIT_CAPACITY 4

typedef int type;

typedef struct
{
	type *content; 		// actual content of the vector
	int capacity; 		// capacity allocated
	int length; 		// number of elements
} vector;




// PROTOTYPE FUNCTIONS

#endif