# Program name
PROG = Checkers

# Directory marcos
BDIR = bin
ODIR = obj
SDIR = src
IDIR = include

# Complier
CC = g++

# Options to pass to the compiler
CFLAGS = -std=c++11

# Options to link
LFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

# Object files format: file.o
#_OBJS = AI.o \
#	    Application.o \
#	    ApplicationState.o \
#	    ApplicationStateManager.o \
#	    Button.o \
#	    CheckersBoard.o \
#	    GameOverState.o \
#	    GameState.o \
#	    main.o \
#	    MenuState.o \
#	    Piece.o \
#	    Player.o \
#	    RealPlayer.o \
#	    Texture.o
#
#OBJS = $(patsubst %,$())
SRC = $(wildcard **/*.cpp)
OBJS = $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SRC))

# Main binary file
all: $(OBJS)
	@mkdir -p $(BDIR)
	$(CC) $(CFLAGS) -I$(IDIR) -o $(BDIR)/$(PROG) $^ $(LFLAGS)

# Compiles .cpp files into .o files
$(ODIR)/%.o: $(SDIR)/%.cpp
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -I$(IDIR) -MMD -c -o $@ $<

# clean for removing all the object files
clean:
	rm -rf $(ODIR) $(BDIR)

test:
	echo $(OBJS)
