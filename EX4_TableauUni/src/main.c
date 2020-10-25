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
	int size, valMax, smallest, biggest, indexOfFive;

	printf("De quelle taille doit être votre tableau?\nTaille : ");
	scanf("%d", &size);
	
	int tab1[size];
	
	valMax = size / 10;

	//Remplie le tableau
	for (long i = 0; i < size; i++)
	{
		tab1[i] = rand() % valMax;
	}

	printf("Tableau avant Modifications\n");
	PrintTab(size, tab1);
	
	smallest = FindSmallestValueInTab(size, tab1);
	biggest = FindBiggestValueInTab(size, tab1);
	indexOfFive = GetIndexOfValue(size, tab1, 5);

	printf("La plus petite valeur du tableau est  %d\n", smallest);
	printf("La plus grande valeur du tableau est  %d\n", biggest); 
	printf("L'index de la valeur 5 du tableau est %d\n", indexOfFive); 
	


	ReplaceLastByBiggest(size, tab1);
	printf("Tableau apres Modifications\n");
	PrintTab(size, tab1);






	return 0;
}







