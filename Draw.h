/**
 * This module will draw the gallows, category, and the name to guess
 * If no (correct) guesses were made an appropriate amount of "blanks"
 * (lines) will be printed so the guesser can see how many characters
 * they will need to guess
 */
#ifndef DRAW_H
#define DRAW_H
#include "Answer.h"

/**
 * this function draws a gallows
 * and body of the man depending on how many wrong answers the user has given
 */
void draw(Answer *answer);

/**
 * prints the prompt to be guessed
 * 
 * this function prints the letters guessed, otherwise prints an underscore
 */
//void printPrompt(Answer *answer);

#endif