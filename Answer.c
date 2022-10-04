#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Answer.h"

Answer Answer_value(char *category, char *name){
    Answer init = {};

    init.category = category;
    init.name = name;
    int gCap = 32;
    init.guess = malloc(sizeof(char)*gCap);
    init.gWrong = malloc(sizeof(char)*gCap);
    init.wrongcount = 0;

    /*
    //intialization of matrix of the tokenization of the given answer to guess
    int wordCount = 10;
    int cPerWord = 20;
    init.nameToken = malloc(sizeof(char*)*wordCount);
    for(int i=0; i<wordCount; i++) init.nameToken[i] = malloc(sizeof(char)*cPerWord);

    char *saveptr = NULL;
    char *token = strtok_r(name, " ", &saveptr);
    init.numOfTokens = 0;
    while(token != NULL){
        init.numOfTokens++;
        strcpy(init.nameToken[init.numOfTokens-1], token);
        printf("New token: %s\n", init.nameToken[init.numOfTokens-1]);
        token = strtok_r(NULL, " ", &saveptr);
    }
    */
    return init;
}