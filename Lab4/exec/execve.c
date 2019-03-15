/**
 * This code is intended to 
 * show the command of execve
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char ** argv) {
    char *env[] = {"LS_COLORS=fi=04;33;44",NULL}; 
    char *arg[] = {"ls", "-l", NULL};
    printf("Using *execve* to exec ls -l\n");
    execve("/bin/ls", arg, env);
    /* Print in human-friendly form */
    printf("Program Terminated\n");
    return 0;
}