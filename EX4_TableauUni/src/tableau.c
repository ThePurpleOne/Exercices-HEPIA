/*===========================================================================*
   Auteur   : STIRNEMANN Jonas
   Date création : 25/10/2020
=============================================================================
   Descriptif: Lib allowing to manage arrays 
=*===========================================================================*/

#include <stdio.h>
#include "../headers/tableau.h"


/*---------------------------------------------------------------------------
	PrintTab(int sizeOfTab, int *tab )
	-------------------------------------------------------------------------
	Description	:	Print a tab
	Input		:	int array size, pointer to array  
	output		:	
*---------------------------------------------------------------------------*/
void PrintTab(int sizeOfTab, int *tab )
{
	for (long i = 0; i < sizeOfTab; i++)
	{
		printf("TAB[%ld] = %d\n", i, *(tab + i) );
	}
}

/*---------------------------------------------------------------------------
	FindSmallestValueInTab(int sizeOfTab, int *tab)
	-------------------------------------------------------------------------
	Description	:	Find the smallest value contained in a given array
	Input		:	int array size, pointer to array  
	output		:	int smallest value 
*---------------------------------------------------------------------------*/
int FindSmallestValueInTab(int sizeOfTab, int *tab )
{
	int smallestValue = sizeOfTab;
	
	for (int i = 0; i < sizeOfTab; i++)
	{
		if(  *(tab + i) < smallestValue ) // smaller than actual smallest?
		{
			smallestValue = *(tab + i);
		}
	}
	
	return smallestValue;
}

/*---------------------------------------------------------------------------
	FindBiggestValueInTab(int sizeOfTab, int *tab)
	-------------------------------------------------------------------------
	Description	:	Find the Biggest value contained in a given array
	Input		:	int array size, pointer to array  
	output		:	int Biggest value 
*---------------------------------------------------------------------------*/
int FindBiggestValueInTab(int sizeOfTab, int *tab )
{
	int biggestValue = 0;
	
	for (int i = 0; i < sizeOfTab; i++)
	{
		if(  *(tab + i) > biggestValue ) // bigger than actual biggest?
		{
			biggestValue = *(tab + i);
		}
	}
	
	return biggestValue;
}

/*---------------------------------------------------------------------------
	GetIndexOfValue(int sizeOfTab, int *tab, int valueToLookFor)
	-------------------------------------------------------------------------
	Description	:	returns the index of the first occurence
					of a specified value
	Input		:	int array size, pointer to array, int valueToLookFor 
	output		:	int index of the first occurence of the value 
*---------------------------------------------------------------------------*/
int GetIndexOfValue(int sizeOfTab, int *tab, int valueToLookFor)
{
	for (int i = 0; i < sizeOfTab; i++)
	{
		if(  *(tab + i) == valueToLookFor ) // value found ?
		{
			return(i);
		}
	}
	return(-1);
}

/*---------------------------------------------------------------------------
	ReplaceLastByBiggest(int sizeOfTab, int *tab)
	-------------------------------------------------------------------------
	Description	:	Replace the last value of the array by the biggest value
					(exchange the last with biggest)
	Input		:	int array size, pointer to array  
	output		:	
*---------------------------------------------------------------------------*/
void ReplaceLastByBiggest(int sizeOfTab, int *tab)
{
	int biggest, biggestIndex, bufferLast;

	//Find the biggest value and its index
	biggest = FindBiggestValueInTab(sizeOfTab, tab);
	biggestIndex = GetIndexOfValue(sizeOfTab, tab, biggest);
	
	//get the value of the last index 
	bufferLast = *(tab + sizeOfTab); 

	//put the last value at the biggest value index
	*(tab + biggestIndex) = bufferLast;

	//put the biggest value at last index 
	*(tab + sizeOfTab) = biggest;
}







