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

int aContainsG(Answer *answer, char *guess)
{
    char *gup = malloc(sizeof(char)), *gdown = malloc(sizeof(char));

    gup = strcpy(gup, guess);
    gup[0] = toupper(gup[0]);

    gdown = strcpy(gdown, guess);
    gdown[0] = tolower(gdown[0]);

    if(strstr(answer->name, gup) == NULL && strstr(answer->name, gdown) == NULL){
        return 0;
    }else{
        return 1;
    }
}

void setGuess(Answer *answer, char *guess, int wrong)
{
    if(wrong){
        answer->guess[answer->guessCount] = guess[0];
        answer->gWrong[answer->guessCount++] = wrong;
    }else{
        answer->guess[answer->guessCount] = guess[0];
        answer->wrongcount++;
    }
}