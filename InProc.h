/**
 * this module houses all the functions needed to
 * process user input for the hangman game
 */
#ifndef INPROC_H
#define INPROC_H

/**
 * compares user-inputted category with the predetermined list
 */
int isCategory(char **a, char *x, int n);

/**
 * cycles through each indivdual character and converts to lower case
 */
void toLower(char *s, int n);

/**
 * capitalize the first character of every word in a space seperated string
 */
void capFirstChar(char *s, int n);

/**
 * Returns a malloced string pointer with removed \n char from getline() function
 */
char* getLineNoNewLine();

/**
 * returns a malloced array of size 2 with the upper and lower case version of given guess
 */
char** getUpperLower(char *guess);

/**
 * return 1 if the answer contains the guess
 * else return 0
 */
int aContainsG(Answer *answer, char *guess);

/**
 * this function records the guess and increments index in gWrong if not found
 */
void setGuess(Answer *answer, char *guess, int wrong);

#endif