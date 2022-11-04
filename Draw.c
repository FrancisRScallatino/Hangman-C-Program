#include <stdio.h>

#include "Draw.h"
#include "Answer.h"

void draw(Answer *answer)
{
    printf("You're category is: %s\n", answer->category);

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
    }else{
        printf("|\n");
    }

    //abs
    answer->wrongcount>4 ? printf("|      |\n") : printf("|\n");

    //legs
    if(answer->wrongcount == 6){
        printf("|     /\n");
    }else if(answer->wrongcount > 6){
        printf("|     / \\\n");
    }else{
        printf("|\n");
    }

    printf("|\n");
    printf("------------\n");

    //printPrompt(answer);
}

/*void printPrompt(Answer *answer)
{
    
}*/