#include <stdio.h>

void draw(int wGuessCount)
{
    printf("\n--------\n");
    printf("|      |\n");
    wGuessCount<1 ? printf("|\n") : printf("|      o\n");
}