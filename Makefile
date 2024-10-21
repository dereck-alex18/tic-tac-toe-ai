# Makefile

CC = gcc
CFLAGS = -Wall -g -I./include
SRC_DIR = ./src
OBJ_DIR = ./build
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
EXEC = tic_tac_toe

# Ensure the build directory exists
all: $(OBJ_DIR) $(EXEC)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Link all object files to create the executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(CFLAGS) -o $@

# Compile .c files to .o files in the build directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC)

# Run the program
run: all
	./$(EXEC)
