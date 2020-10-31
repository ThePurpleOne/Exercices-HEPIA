/*===========================================================================*
   Auteur   : STIRNEMANN Jonas
   Date création : 25/10/2020
=============================================================================
   Descriptif: Lib allowing to manage arrays 
=*===========================================================================*/

#include <stdio.h>
#include "../headers/tableau.h"

///  Print a tab
/// @param sizeOfTab Size of array
/// @param tab Array you want to print
void PrintTab(int sizeOfTab, int *tab )
{
	for (long i = 0; i < sizeOfTab; i++)
	{
		printf("TAB[%ld] = %d\n", i, *(tab + i) );
	}
}


///  Return the smallest value contained in a given array
/// @param sizeOfTab Size of array
/// @param tab Array you're looking in
/// @return smallest value
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


///  Return the Biggest value contained in a given array
/// @param sizeOfTab Size of array
/// @param tab Array you're looking in
/// @return biggest value
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


///  Return the index of the first occurence of specified value
/// @param sizeOfTab Size of array
/// @param tab Array you're looking in
/// @param valueToLookFor Value you're looking for
/// @return index of first occurencce of specified value
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


///  Replace the last value of the array by the biggest value (exchange the last with biggest)
/// @param sizeOfTab Size of array
/// @param tab Array to modify
void ReplaceLastByBiggest(int sizeOfTab, int *tab)
{
	int biggest, biggestIndex, bufferLast;

	//Find the biggest value and its index
	biggest = FindBiggestValueInTab(sizeOfTab, tab);
	biggestIndex = GetIndexOfValue(sizeOfTab, tab, biggest);
	
	//get the value of the last index 
	bufferLast = *(tab + sizeOfTab - 1); 

	//put the last value at the biggest value index
	*(tab + biggestIndex) = bufferLast;

	//put the biggest value at last index 
	*(tab + sizeOfTab - 1) = biggest;

}







