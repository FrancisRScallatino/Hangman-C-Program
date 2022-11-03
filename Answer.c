#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Answer.h"

Answer Answer_value(char *category, char *name){
    Answer init = {};

    init.category = category;
    init.name = name;
    int gCap = 32;
    init.guess = calloc(sizeof(char), gCap);
    init.gWrong = calloc(sizeof(char), gCap);
    init.guessCount = 0;
    init.wrongcount = 0;
    
    return init;
}