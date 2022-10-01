/**author: Francis S Scallatino
 * 
 * This is the main module. It will handle output of information
 * about the game and retrieve user input
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void newLine(){printf("\n");}

int isCategory(char **a, char *x, int n)
{
    for(int i=0; i<n; i++){
        if(!strcasecmp(x, a[i])) return 1;
    }

    return 0;
}

void printCategories(char **cat, int n)
{
    printf("Acceptable categories include: ");
    for(int i=0; i<n; i++){
        if(i != 0) printf(", ");
        printf("%s", cat[i]);
    }
    newLine();
}

int main ()
{
    char *category[] = {"Movies", "TV", "Songs"};
    int numOfCategories = (int) sizeof(category)/sizeof(char*);

    printf("Welcome to HANGMAN!\nThe game where you risk life and limb to guess what you're opponent is thinking!\n\n");
    printf("When you're ready to put your life on the line, give me a catgeory!\n");
    
    printCategories(category, numOfCategories);

    char *chosenCategory = malloc(sizeof(category));
    printf("Enter here: ");
    scanf("%s", chosenCategory);
    newLine();
    
    while(!isCategory(category, chosenCategory, numOfCategories)){
        printf("Whoops, that's not an acceptable cetegory!\n");

        printCategories(category, numOfCategories);

        printf("Try again: ");
        scanf("%s", chosenCategory);
        newLine();
    }

    return (0);
}