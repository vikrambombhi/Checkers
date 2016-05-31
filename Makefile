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
CFLAGS = -c -Wall -std=c++11
# Options to link
LFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
# Source files
SRC = $(wildcard $(SDIR)/*.cpp) # wildcard is used to searched for all cpp files in dir
# Header files
HDR = $(wildcard $(IDIR)/*.h)
# Object files
OBJ = $(patsubst %.cpp, %.o, $(SRC)) # patsubst is used to change all source files to object files
# Main binary file
all: $(OBJ)
	@mkdir $(BDIR)
	@mkdir $(ODIR)
	$(CC) $(LFLAGS) $(OBJS) -I$(BDIR) -o $(BDIR)/$(PROJECT)

# Indiviual objects files split up so they are only made when nessacry
AI.o : AI.h AI.cpp GameState.h
	$(CC) $(CFLAGS) AI.cpp

Application.o : Application.h Application.cpp ApplicationState.h ApplicationStateManager.h Texture.h
	$(CC) $(CFLAGS) Application.cpp

ApplicationState.o : ApplicationState.h ApplicationState.cpp
	$(CC) $(CFLAGS) ApplicationState.cpp

ApplicationStateManager.o : ApplicationStateManager.h ApplicationStateManager.cpp MenuState.h GameState.h GameOverState.h
	$(CC) $(CFLAGS) ApplicationStateManager.cpp

Button.o : Button.h Button.cpp GameState.h Texture.h Application.h
	$(CC) $(CFLAGS) Button.cpp

CheckersBoard.o : CheckersBoard.h CheckersBoard.cpp GameState.h Texture.h
	$(CC) $(CFLAGS) CheckersBoard.cpp

GameOverState.o : GameOverState.h GameOverState.cpp Texture.h
	$(CC) $(CFLAGS) GameOverState.cpp

GameState.o : GameState.h GameState.cpp ApplicationStateManager.h CheckersBoard.h Player.h AI.h RealPlayer.h Button.h Texture.h
	$(CC) $(CFLAGS) GameState.cpp

main.o : main.cpp Application.h
	$(CC) $(CFLAGS) main.cpp

MenuState.o : MenuState.h MenuState.cpp Texture.h Button.h
	$(CC) $(CFLAGS) MenuState.cpp

Piece.o : Piece.h Piece.cpp
	$(CC) $(CFLAGS) Piece.cpp

Player.o : Player.h Player.cpp CheckersBoard.h Button.h GameState.h
	$(CC) $(CFLAGS) Player.cpp

RealPlayer.o : RealPlayer.h RealPlayer.cpp GameState.h
	$(CC) $(CFLAGS) RealPlayer.cpp

Texture.o : Texture.h Texture.cpp
	$(CC) $(CFLAGS) Texture.cpp

# Compiles .cpp files into .o files
.cpp.o:
	$(CC) $(CFLAGS) -I$(ODIR) -o $@ $<
# clean for removing all the object files
clean:
	\rm $(ODIR)/* $(BDIR)/*

tempClean:
	\rm -r $(BDIR)
	\rm $(SDIR)/*.o
