CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

CFILES = Hangman.c Draw.c Answer.c InProc.c
OBJECTS = Hangman.o Draw.o Answer.o InProc.o

BINARY = Hangman

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

Hangman.o: Hangman.c
	$(CC) $(CFLAGS) -c $<

Draw.o: Draw.c Draw.h
	$(CC) $(CFLAGS) -c $<

Answer.o: Answer.c Answer.h
	$(CC) $(CFLAGS) -c $<

InProc.o: InProc.c InProc.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(BINARY) $(OBJECTS)
