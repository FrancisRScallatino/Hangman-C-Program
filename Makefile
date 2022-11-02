CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

CFILES = Hangman.c Draw.c Answer.c InProc.c
OBJECTS = Hangman.o Draw.o Answer.o InProc.o

BINARY = Hangman

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(BINARY) $(OBJECTS)
