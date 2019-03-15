/**
 * This code is intended to show
 * the result of using execv
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char** argv) {
    char *arg[] = {"ls", "-l", NULL};
    printf("Using execv to exec is -l...\n");
    execv("/bin/ls", arg);
    printf("Program Terminated");

}