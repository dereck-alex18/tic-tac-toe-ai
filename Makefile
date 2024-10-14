# Makefile

CC = gcc
CFLAGS = -Wall -g
OBJ = main.o game.o board.o player.o menus.o ai.o
EXEC = tic_tac_toe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o tic_tac_toe $(OBJ)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<


run: all
	./$(EXEC)

clean:
	rm -f *.o tic_tac_toe
