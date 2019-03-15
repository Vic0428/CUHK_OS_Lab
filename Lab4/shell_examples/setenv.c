/**
 * This code is intended to set
 * some environment variables.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv) {
    char *command1[] = {"shutdown", NULL};
    printf("Running shutdown.. it is in /sbin :P\n\n");
    setenv("PATH", "/bin:/usr/bin:.", 1);
    execvp(*command1, command1);

    if(errno == ENOENT) {
        printf("No command found...\n\n");
    }
    else {
        printf("I don't know...\n");
    }
    return 0;
}