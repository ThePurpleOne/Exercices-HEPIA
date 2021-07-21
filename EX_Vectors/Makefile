CXX       := gcc
CXX       := gcc
CXX_FLAGS := -Wall -Wextra

BIN     	:= bin
SRC     	:= src
INCLUDE 	:= include
LIB     	:= lib
LIBRARIES   := 		#Library flags like -lm -lncurses
EXECUTABLE  := main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.c
	@echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) -L $(LIB) $^ -o $@ $(LIBRARIES)

clean:
	@echo "🧹 Clearing..."
	-rm $(BIN)/*

