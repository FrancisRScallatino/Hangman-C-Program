#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

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