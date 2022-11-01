CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

MYps: Hangman.o Draw.o Answer.o InProc.o
	$(CC) $(CFLAGS) $^ -o Hangman

Hangman.o: Hangman.c
	$(CC) $(CFLAGS) -c Hangman.c

Draw.o: Draw.c Draw.h
	$(CC) $(CFLAGS) -c Draw.c

Answer.o: Answer.c Answer.h
	$(CC) $(CFLAGS) -c Answer.c

InProc.o: InProc.c InProc.h
	$(CC) $(CFLAGS) -c InProc.c

clean:
	rm -rf *.o Hangman HangmanD
