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

# Finds all cpp files in project directory
# Format: src/.cpp
SRC = $(wildcard **/*.cpp)

# Makes a list of src file names as .o files
# Format: obj/.o
OBJS = $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SRC))

# Main binary file
all: $(OBJS)
	# Makes bin folder
	@mkdir -p $(BDIR)
	$(CC) $(CFLAGS) -I$(IDIR) -o $(BDIR)/$(PROG) $^ $(LFLAGS)

# Compiles .cpp files into .o files
$(ODIR)/%.o: $(SDIR)/%.cpp
	# Makes obj directory
	@mkdir -p $(ODIR)
	# -MMD generates the dependences
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

# clean for removing all the object files
clean:
	rm -rf $(ODIR) $(BDIR)

test:
	echo $(OBJS)
