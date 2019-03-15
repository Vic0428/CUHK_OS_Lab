/**
 * This code is intended to
 * show that argument array 
 * is an array of pointers.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main() {
    char **arglist = (char **) malloc(3 * sizeof(char *));
    arglist[0] = (char *) malloc(10 * sizeof(char));
    strcpy(arglist[0], "ls");
    arglist[1] = (char *) malloc(10 * sizeof(char));
    strcpy(arglist[1], "-al");
    arglist[2] = NULL;

    execvp(*arglist, arglist);
    return 0;

}