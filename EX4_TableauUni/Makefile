all : tableauUni

tableauUni : obj/main.o obj/tableau.o
	gcc -lm -o tableauUni obj/main.o obj/tableau.o

obj/main.o : src/main.c
	gcc -o obj/main.o -c src/main.c

obj/tableau.o : src/tableau.c
	gcc -o obj/tableau.o -c src/tableau.c
