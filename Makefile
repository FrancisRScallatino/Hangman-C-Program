GC = gcc
WFLAGS = -Wall -Werror -Wextra

MYps: Hangman.o
	$(GC) $(WFLAGS) $^ -o Hangman

Hangman.o: Hangman.c
	$(GC) $(WFLAGS) -c $^

clean:
	rm -rf *.o Hangman HangmanD

db: Hangman.o
	$(GC) $(WFLAGS) -g $^ -o HangmanD