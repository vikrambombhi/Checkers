# Project name (binary file name)
PROJECT = Checkers
# Directory marcos
BDIR = bin
ODIR = obj
SDIR = src
IDIR = include
# Complier
CC = g++
# Options to pass to the compiler
CFLAGS = -c -std=c++11
# Options to link
LFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
# Source files format: src/file.cpp
SRC = $(wildcard **/*.cpp) # wildcard is used to searched for all cpp files in dir
# Object files format: file.o
OBJ = $(patsubst $(SDIR)/%.cpp, %.o, $(SRC)) # patsubst is used to change all source files to object files
# Main binary file
all: $(OBJ)
	@mkdir -p $(BDIR)
	@mkdir -p $(ODIR)
	$(CC) $(LFLAGS) $(OBJS) -I$(BDIR) -o $(BDIR)/$(PROJECT)

# Indiviual objects files split up so they are only made when nessacry
AI.o : AI.cpp AI.h GameState.h
	$(CC) $(CFLAGS) $< -o $@

Application.o : Application.cpp Application.h ApplicationState.h ApplicationStateManager.h Texture.h
	$(CC) $(CFLAGS) $< -o $@

ApplicationState.o : ApplicationState.cpp ApplicationState.h
	$(CC) $(CFLAGS) $< -o $@

ApplicationStateManager.o : ApplicationStateManager.cpp ApplicationStateManager.h MenuState.h GameState.h GameOverState.h
	$(CC) $(CFLAGS) $< -o $@

Button.o : Button.cpp Button.h GameState.h Texture.h Application.h
	$(CC) $(CFLAGS) $< -o $@

CheckersBoard.o : CheckersBoard.cpp CheckersBoard.h GameState.h Texture.h
	$(CC) $(CFLAGS) $< -o $@

GameOverState.o : GameOverState.cpp GameOverState.h Texture.h
	$(CC) $(CFLAGS) $< -o $@

GameState.o : GameState.cpp GameState.h ApplicationStateManager.h CheckersBoard.h Player.h AI.h RealPlayer.h Button.h Texture.h
	$(CC) $(CFLAGS) $< -o $@

main.o : main.cpp Application.h
	$(CC) $(CFLAGS) $< -o $@

MenuState.o : MenuState.cpp MenuState.h Texture.h Button.h
	$(CC) $(CFLAGS) $< -o $@

Piece.o : Piece.cpp Piece.h
	$(CC) $(CFLAGS) $< -o $@

Player.o : Player.cpp Player.h CheckersBoard.h Button.h GameState.h
	$(CC) $(CFLAGS) $< -o $@

RealPlayer.o : RealPlayer.cpp RealPlayer.h GameState.h
	$(CC) $(CFLAGS) $< -o $@

Texture.o : Texture.cpp Texture.h
	$(CC) $(CFLAGS) $< -o $@

# Compiles .cpp files into .o files
$(ODIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@
# clean for removing all the object files
clean:
	@rm $(ODIR)/* $(BDIR)/*
	@rmdir $(ODIR)
	@rmdir $(BDIR)

tempClean:
	@rm $(SDIR)/*.o
	@rm -r $(BDIR)
	@rm -r $(ODIR)

test:
	@echo $(SRC)
	@echo $(OBJ)
