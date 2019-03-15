/**
 * This code is intended to show
 * the use of execle. 
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    /* Define enviroment variables */
    char *env[] = {"LS_COLORS=fi=04;33;44",NULL};
    printf("Using *execle* to exec ls -l\n");
    /* execle() using pathname, argument list, env to execute the program */
    execle("/bin/ls", "ls", "-l", NULL, env);
    printf("Program Terminated");
    return 0;
}