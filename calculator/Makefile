# Define the compiler
CC = gcc

# Define the source file
SRC = calculator.c

# Define the object file
OBJ = $(SRC:.c=.o)  # Replace .c extension with .o

# Define the executable file
EXEC = calculator

# Target to compile the program
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

# Target to compile individual object files
.c.o:
	$(CC) -c $< -o $@

# Target to clean up object files
clean:
	rm -f $(OBJ) $(EXEC)


