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

void newLine(){printf("\n");}

//checks the list of categories for the user-entered category
int isCategory(char **a, char *x, int n)
{
    for(int i=0; i<n; i++){
        if(!strcasecmp(x, a[i])) return 1;
    }

    return 0;
}

//prints all the vailable categories
void printCategories(char **cat, int n)
{
    printf("Acceptable categories include: ");
    for(int i=0; i<n; i++){
        if(i != 0) printf(", ");
        printf("%s", cat[i]);
    }
    newLine();
}

void exitProgram(){exit(EXIT_SUCCESS);}

void toLower(char *s, int n)
{
    for(int i=0; i<n; i++) s[i]= tolower(s[i]);
}

void capFirstChar(char *s, int n)
{
    s[0] = toupper(s[0]);
    for(int i=1; i<n; i++){
        if(s[i-1] != ' '){
            s[i] = tolower(s[i]);
        }else{
            s[i] = toupper(s[i]);
        }
    }
}

int main ()
{
    char *category[] = {"Movies", "TV", "Songs"};
    int numOfCategories = (int) sizeof(category)/sizeof(char*);

    //introduction
    printf("Welcome to HANGMAN!\nThe game where you risk life and limb to guess what you're opponent is thinking!\n\n");
    printf("When you're ready to put your life on the line, give me a catgeory!\n");
    
    printCategories(category, numOfCategories);

    char *chosenCategory = malloc(sizeof(category));
    printf("Enter here: ");
    scanf("%s", chosenCategory);
    newLine();
    
    //make sure the user-entered category is in the predefined list
    while(!isCategory(category, chosenCategory, numOfCategories)){
        if(strcmp(chosenCategory, "exit") == 0) exitProgram();

        printf("Whoops, that's not an acceptable cetegory!\n");

        printCategories(category, numOfCategories);

        printf("Try again: ");
        scanf("%s", chosenCategory);
        newLine();
    }
    toLower(chosenCategory, strlen(chosenCategory)); //normalize the user-given category
    
    int buffSize = 100;                         //allocate space for the prompt to guess
    char *name= malloc(sizeof(char)*buffSize);  //array to store the prompt to guess
    printf("You have chosen %s!\nWhat do you want you opponent to guess?\n", chosenCategory);
    printf("Enter here: ");
    fgets(name, buffSize, stdin);
    scanf ("%[^\n]%*c", name);

    if(strcmp(name, "exit") == 0) exitProgram();
    
    //make sure the prompt the user entered is really what they want their opponent to guess
    char *retype = malloc(sizeof(char)*30);
    strcpy(retype, "y");
    while(strcmp(retype, "y") == 0){
        capFirstChar(name, strlen(name));       //normalize user-input of the prompt
        printf("\nYou chose \"%s\"\n", name);
        printf("If you'd like to retype your answer, type \"y\", if not type anything else: ");
        scanf("%c", retype);

        if(strcmp(name, "exit") == 0) exitProgram();

        if(strcmp(retype, "y") == 0){
            printf("Enter here: ");
            fgets(name, buffSize, stdin);   //read the entire line
            scanf ("%[^\n]%*c", name);      //get and store the whole line until the \n character

            if(strcmp(name, "exit") == 0) exitProgram();
        }else{
            strcpy(retype, "n");
        }
    }
    free(retype);
    
    //system("clear");

    //Answer a = Answer_value(chosenCategory, name);
    //printf("\n%s\n", a.name);

    draw();

    return (0);
}