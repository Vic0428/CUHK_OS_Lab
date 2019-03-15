/**
 * This code is intended to show
 * the function of waitpid 
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int pid;
    int status;
    if(!(pid = fork())) {
        printf("My pid: %d\n", pid);
        exit(0);
    }
    waitpid(pid, &status, WUNTRACED);
    if(WIFEXITED(status)) {
        printf("Exit normally\n");
        printf("Exit status: %d\n", WEXITSTATUS(status));
    }
    else {
        printf("Exit not normally\n");
    }
    return 0;
}