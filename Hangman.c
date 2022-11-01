/**author: Francis S Scallatino
 * 
 * This is the main module. It will handle output of information
 * about the game and retrieve user input
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Draw.h"
#include "Answer.h"
#include "InProc.h"

void newLine(){printf("\n");}

//prints all the available categories
void printCategories(char **cat, int n)
{
    printf("Acceptable categories include: ");
    for(int i=0; i<n; i++){
        if(i != 0) printf(", ");
        printf("%s", cat[i]);
    }
    newLine();
}

//check if user entered exit or quit to kill the program
void checkIfExit(char *str){
    if(strcmp(str, "exit") == 0 || strcmp(str, "quit") == 0) exit(EXIT_SUCCESS);
}

//clear the temrinal
void clear(){printf("\e[1;1H\e[2J");}

int main ()
{
    char *category[] = {"Movies", "TV", "Songs"};
    int numOfCategories = (int) sizeof(category)/sizeof(char*);
    int catIndex;

    //introduction
    clear();
    printf("Welcome to HANGMAN!\nThe game where you risk life and limb to guess what you're opponent is thinking!\n\n");
    printf("When you're ready to put your life on the line, give me a catgeory!\n");
    
    printCategories(category, numOfCategories);
    
    printf("Enter here: ");
    char *chosenCategory = getLineNoNewLine();
    checkIfExit(chosenCategory);
    newLine();
    
    //make sure the user-entered category is in the predefined list
    while((catIndex = isCategory(category, chosenCategory, numOfCategories)) == -1){
        clear();
        printf("Whoops, that's not an acceptable cetegory!\n");

        printCategories(category, numOfCategories);

        free(chosenCategory);
        printf("Try again: ");
        chosenCategory = getLineNoNewLine();
        checkIfExit(chosenCategory);
        newLine();
    }
    toLower(chosenCategory, strlen(chosenCategory)); //normalize the user-given category
    
    clear();
    printf("You have chosen %s!\nWhat do you want you opponent to guess?\n", category[catIndex]);
    printf("Enter here: ");
    char *name = getLineNoNewLine();

    checkIfExit(name);
    
    //make sure the prompt the user entered is really what they want their opponent to guess
    char *retype = malloc(sizeof(char)*100);
    strcpy(retype, "y");
    while(strcmp(retype, "y") == 0){
        clear();
        capFirstChar(name, strlen(name));       //normalize user-input of the prompt
        printf("\nYou chose \"%s\"\n", name);
        printf("If you'd like to retype your answer, type \"y\", if not type anything else: ");
        retype = getLineNoNewLine();

        checkIfExit(name);

        if(strcmp(retype, "y") == 0){
            printf("Enter here: ");
            free(name);
            name = getLineNoNewLine();

            checkIfExit(name);
        }else{
            strcpy(retype, "n");
        }
    }
    free(retype);

    Answer answer = Answer_value(chosenCategory, name);

    int not1Char = 0;
    int notLetter = 0;
    while(1){
        //clear();
        draw(++answer.wrongcount);

        char *guess = calloc(sizeof(char), 100);

        if(not1Char){
            printf("That means 1 single letter! (-_- )\n");
        }
        if(notLetter){
            printf("Keyword being LETTER!\n");
        }
        printf("What letter would you like to risk your life on? ");
        guess = getLineNoNewLine();

        checkIfExit(guess);
        
        if(guess[1] != 0){
            not1Char = 1;
        }else{
            not1Char = 0;

            if(isalpha(guess[0]) > 0){  //if not alpha
                notLetter = 0;
            }else{
                notLetter = 1;

                //checkGuess(guess);
            }
        }
        
        free(guess);
    }

    return (0);
}