#include <stdio.h>

#include "Draw.h"
#include "Answer.h"

void draw(int wGuessCount)
{
    printf("\n--------\n");
    printf("|      |\n");
    wGuessCount<1 ? printf("|\n") : printf("|      o\n");
}