#arguments $(arg)
CCC = gcc
OPT = -lm
OBJ = obj


all : tableauUni


pre-build:
	mkdir -p obj

tableauUni : obj/main.o obj/tableau.o
	$(CCC) -o tableauUni $(OBJ)/main.o $(OBJ)/tableau.o $(OPT) 

obj/main.o : src/main.c
	$(CCC) -o $(OBJ)/main.o -c src/main.c $(OPT) 

obj/tableau.o : src/tableau.c
	$(CCC) -o $(OBJ)/tableau.o -c src/tableau.c $(OPT) 
