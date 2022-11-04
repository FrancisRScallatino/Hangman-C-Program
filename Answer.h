/**
 * this module tracks all important user information
 * throughout the games life cycle
 */

#ifndef ANSWER_H
#define ANSWER_H

typedef struct Answer{
    char *category; //user-given category for the prompt
    char *name;     //user-given prompt for player to guess
    char *guessed;  //array to track which characters in name are guessed
    int *gWrong;    //array to track wrong guesses
    int guessCount; //number of guesses
    int wrongcount; //number of wrong guesses
}Answer;

/**
 * initialize an Answer struct
 */
Answer Answer_value(char *category, char *name);

#endif