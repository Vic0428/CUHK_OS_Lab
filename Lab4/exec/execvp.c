/**
 * This code is intended to show the power of 
 * execvp
 */ 
#include <stdio.h>
#include <unistd.h>

int main() {
    char *arg[] = {"ls", "-l", NULL};
    printf("Using *execvp* to exec ls -l..\n");
    execvp("ls", arg);
    printf("Program Terminated.\n");
    return 0;
}