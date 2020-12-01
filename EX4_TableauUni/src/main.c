/*===========================================================================*
   Auteur   : STIRNEMANN Jonas
   Date création : 25/10/2020
=============================================================================
   Descriptif: Gestion de tableaux Unidimensionnels
=*===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "../headers/tableau.h"

int main(int argc, char const *argv[])
{
	int size, valMax, smallest, biggest, indexOfFive, valueToLookFor, averageOfValues, variance;

	printf("De quelle taille doit être votre tableau?\nTaille du tableau: ");
	scanf("%d", &size);

	printf("Quelle est la valeur recherchée\nValeur: ");
	scanf("%d", &valueToLookFor);
	
	int tab1[size];
	
	valMax = size / 10;

	//Remplie le tableau
	for (long i = 0; i < size; i++)
	{
		tab1[i] = rand() % valMax;
	}

	// printf("Tableau avant Modifications\n");
	// PrintTab(size, tab1);
	
	smallest = FindSmallestValueInTab(size, tab1);
	biggest = FindBiggestValueInTab(size, tab1);
	indexOfFive = GetIndexOfValue(size, tab1, valueToLookFor);
	averageOfValues = GetAverage(size, tab1);
	variance = GetVariance(size, tab1, averageOfValues);

	printf("\n\n[+ PETITE] = [%d]\n", smallest);
	printf("[+ GRANDE] = [%d]\n", biggest); 
	printf("[INDEX OF %d] = [%d]\n", valueToLookFor, indexOfFive); 
	printf("[AVERAGE] = [%d]\n", averageOfValues); 
	printf("[VARIANCE] = [%d]\n", variance); 

	ReplaceLastByBiggest(size, tab1);
	printf("Dernière valeur échangée avec la plus grande!\n");
	PrintTab(size, tab1);

	BubbleSort(size, tab1);
	printf("\n\n\n[Tableau trié]\n");
	PrintTab(size, tab1);

	//PrintTab(size, tab1);

	return 0;
}







