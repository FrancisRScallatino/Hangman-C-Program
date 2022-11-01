/**
 * This module will draw the gallows, category, and the name to guess
 * If no (correct) guesses were made an appropriate amount of "blanks"
 * (lines) will be printed so the guesser can see how many characters
 * they will need to guess
 */
#ifndef DRAW_H
#define DRAW_H

/**
 * this function draws a gallows
 * and body of the man depending on how many wrong answers the user has given
 */
void draw(int wGuessCount);

#endif