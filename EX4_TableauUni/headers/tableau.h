#ifndef _TABLEAU_H_
#define _TABLEAU_H_


//http://malaspinas.academy/

//############## Variables Globales et structs ##############


//############## FONCTIONS PROTOTYPES ##############
void PrintTab(int sizeOfTab, int *tab );
int FindSmallestValueInTab(int sizeOfTab, int *tab );
int FindBiggestValueInTab(int sizeOfTab, int *tab );
int GetIndexOfValue(int sizeOfTab, int *tab, int valueToLookFor);
void ReplaceLastByBiggest(int sizeOfTab, int *tab);
//############## END FONCTIONS PROTOTYPES ##############

#endif
