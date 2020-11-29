/*===========================================================================*
   Auteur   : STIRNEMANN Jonas
   Date création : 25/10/2020
=============================================================================
   Descriptif: Lib allowing to manage arrays 
=*===========================================================================*/

#include <stdio.h>
#include <math.h>
#include "../headers/tableau.h"

///  Print a tab
/// @param sizeOfTab Size of array
/// @param tab Array you want to print
void PrintTab(int sizeOfTab, int *tab )
{
	for (long i = 0; i < sizeOfTab; i++)
	{
		printf("TAB[%.3ld] = %d\n", i, *(tab + i) );
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
	//not found
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


///  Return the average of values in a tab
/// @param sizeOfTab Size of array
/// @param tab Array you're making the average of
/// @return the average of the values from the tab
int GetAverage(int sizeOfTab, int *tab)
{
	int sum;
	for (int i = 0; i < sizeOfTab; i++)
	{
		sum += *(tab + i);
	}
	return (sum / sizeOfTab);
}

///  Return the variance 
/// @param sizeOfTab Size of array
/// @param tab Array you're making the average of
/// @param average average of the values from the tab  
/// @return the variance of the values from the tab 
int GetVariance(int sizeOfTab, int *tab, int average)
{
	float var;

	for (int i = 0; i < sizeOfTab - 1; i++)
	{
		var += pow( (*(tab + i) - average), 2 );
	}
	return ( var / (float)sizeOfTab );
}


///  Bubble sort the array 
/// @param sizeOfTab Size of array
/// @param tab Array to modify
void BubbleSort(int sizeOfTab, int *tab)
{
	#define SWAPPED 10
	int swapped = SWAPPED;
	int temp;

	//elements still have been swapped ?
	while (swapped == SWAPPED) 
	{
		swapped = 42; //random value to clear swapped	
		for (size_t i = 0; i < sizeOfTab - 1; i++)
		{
			if( *(tab + i) > *(tab + i + 1 ) ) //first bigger than second ?
			{
				swapped = SWAPPED; //set the swapped flag
				//swap elements
				temp = *(tab + i);
				*(tab + i) = *(tab + i + 1);
				*(tab + i + 1) = temp;
			}
		}
	}
}






