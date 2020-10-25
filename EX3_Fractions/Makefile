all : fractions

fractions : obj/main.o obj/fractions.o
	gcc -lm -o fractions obj/main.o obj/fractions.o

obj/main.o : src/main.c
	gcc -o obj/main.o -c src/main.c

obj/fractions.o : src/fractions.c
	gcc -o obj/fractions.o -c src/fractions.c
