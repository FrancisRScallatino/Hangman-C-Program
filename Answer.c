#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Answer.h"

Answer Answer_value(char *category, char *name){
    Answer init = {};

    init.category = category;
    init.name = name;
    
    init.guessed = calloc(sizeof(char), strlen(name)+1);
    for(int i=0; init.name[i] != 0; i++){
        if(!(isalpha(init.name[i]) || isdigit(init.name[i]))){
            init.guessed[i] = 1;
        }
    }

    init.gWrong = calloc(sizeof(char), 8);

    init.guessCount = 0;
    init.wrongcount = 0;
    
    return init;
}