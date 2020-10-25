all : fractions

fractions : main.o fractions.o
	gcc -lm -o fractions main.o fractions.o

main.o : main.c
	gcc -o main.o -c main.c

fractions.o : fractions.c
	gcc -o fractions.o -c fractions.c
