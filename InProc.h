/**
 * this module houses all the functions needed to
 * process user input for the hangman game
 */

//compares user-inputted category with the predetermined list
int isCategory(char **a, char *x, int n);

//cycles through each indivdual character and converts to lower case
void toLower(char *s, int n);

//capitalize the first character of every word in a space seperated string
void capFirstChar(char *s, int n);