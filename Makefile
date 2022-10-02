GC = gcc
WFLAGS = -Wall -Werror -Wextra

MYps: Hangman.o Draw.o Answer.o
	$(GC) $(WFLAGS) $^ -o Hangman

Hangman.o: Hangman.c
	$(GC) $(WFLAGS) -c $^

Draw.o: Draw.c Draw.h
	$(GC) $(WFLAGS) -c Draw.c

Answer.o: Answer.c Answer.h
	$(GC) $(WFLAGS) -c Answer.c

clean:
	rm -rf *.o Hangman HangmanD

db: Hangman.o Draw.o Answer.o
	$(GC) $(WFLAGS) -g $^ -o HangmanD