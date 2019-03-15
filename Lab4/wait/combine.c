/**
 * This code is intended to show 
 * how to exec ls in a new process.
 */ 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("This program will use his child process to exec ls\n");
    int pid;
    if(!(pid = fork())) {
        printf("This is the child process\n");
        execlp("/bin/ls", "ls", "-l", NULL);
        return 0;
    }
    else {
        wait(NULL);
        printf("This is the parent process\n");
    }
    printf("Program Terminated\n");
    return 0;
}