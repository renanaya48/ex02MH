#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>

#define MAX_ARGS 512
#define MAX_ARRAY 10
#define MAX_JOBS 512
#define MAX_ARG_LEN 20

/**
 * the function returns the arguments splits.
 * @param args will be the split arguments
 * @param buffer the arguments from the user
 * @param numOfWords number of words
 * @return
 */
char** getArgs(char** args, char* buffer, int* numOfWords){
    char* word;
    //get first token
    word = strtok(buffer, " ");
    int placeInArray=0;
    //walk through other token until the end
    while (word!=NULL){
        args[placeInArray]=word;
        ++placeInArray;
        word=strtok(NULL, " ");
        ++*numOfWords;
    }
    //we got all the args
    while(placeInArray<MAX_ARRAY)
        args[placeInArray++]=0;
    return args;

}

int main() {
    bool waitOrNot = true;
    char **args = malloc(sizeof(char *) * MAX_ARRAY);
    char buffer[MAX_ARRAY];
    int numOfArgs = 0;
    fgets(buffer, MAX_ARRAY + 1, stdin);
    args = getArgs(args, buffer, &numOfArgs);
    if ((args[numOfArgs - 1][0] == '&') && (args[numOfArgs][0] == '\0')) {
        waitOrNot = false;
    }
    printf("%s\n", buffer);
    printf("Hello, World!\n");
    return 0;
}