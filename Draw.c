#include <stdio.h>

#include "Draw.h"
#include "Answer.h"

void draw(Answer *answer)
{
    printf("\n--------\n"); 
    printf("|      |\n");

    //head
    answer->wrongcount<1 ? printf("|\n") : printf("|      o\n");

    //torso
    if(answer->wrongcount == 2){
        printf("|      |\n");
    }else if(answer->wrongcount == 3){
        printf("|     /|\n");
    }else if(answer->wrongcount > 3){
        printf("|     /|\\\n");
    }

    //abs
    answer->wrongcount>4 ? printf("|      |\n") : printf("|\n");

    //legs
    if(answer->wrongcount == 6){
        printf("|     /\n");
    }else if(answer->wrongcount > 6){
        printf("|     / \\\n");
    }

    printf("|\n");
    printf("------------\n");
}