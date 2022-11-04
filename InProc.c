#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Answer.h"
#include "InProc.h"

int isCategory(char **a, char *x, int n)
{
    for(int i=0; i<n; i++){
        if(!strcasecmp(x, a[i])) return i;
    }

    return -1;
}

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

char* getLineNoNewLine()
{
    char* str;
    size_t n = 0;
    ssize_t m;
    
    m = getline(&str, &n, stdin);

    str[m-1] = 0;

    return str;
}

char** getUpperLower(char *guess)
{
    char **gcomp = malloc(sizeof(char*)*2);
    gcomp[0] = malloc(sizeof(char));
    gcomp[1] = malloc(sizeof(char));
    
    gcomp[0][0] = toupper(guess[0]);
    gcomp[1][0] = tolower(guess[0]);

    return gcomp;
}

int aContainsG(Answer *answer, char *guess)
{
    char **gcomp = getUpperLower(guess);

    //if both upper AND lower case versions aren't contained in answer::name
    if(strstr(answer->name, gcomp[0]) == NULL && strstr(answer->name, gcomp[1]) == NULL){
        return 0;
    }else{
        return 1;
    }

    free(gcomp);
}

void setGuess(Answer *answer, char *guess, int contained)
{
    if(!contained){
        answer->gWrong[answer->wrongcount++] = guess[0];
        answer->guessCount++;
    }else{
        answer->guessCount++;
        int i;

        //get index of guess within answer->name
        char **gcomp = getUpperLower(guess);
        char *gindex[] = {strchr(answer->name, gcomp[0][0]),
                          strchr(answer->name, gcomp[1][0])};

        if(gindex[0] == NULL){
            i = (int)(gindex[1]-answer->name);
        }else if(gindex[1] == NULL){
            i = (int)(gindex[0]-answer->name);
        }else{

            /**
             * When a is lesser:
             * (a < b) × a + (b < a) × b = 0 × a + 1 × b = a
             * 
             * When b is lesser:
             * (a < b) × a + (b < a) × b = 1 × a + 0 × b = b
             */
            int a = (int)(gindex[0]-answer->name);
            int b = (int)(gindex[1]-answer->name);
            i = (a<b)*a + (b<a)*b;
        }

        for(i; answer->name[i] != 0; i++){
            if(answer->name[i] == gcomp[0] || answer->name[i] == gcomp[1]){
                answer->guessed = 1;
            }
        }
    }
}