#ifndef ANSWER_H
#define ANSWER_H

typedef struct Answer{
    char *category;
    char **nameToken;
    int numOfTokens;
}Answer;

/**
 * initialize an Answer struct
 */
Answer Answer_value(char *category, char *name);

#endif