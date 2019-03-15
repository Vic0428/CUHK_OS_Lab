/**
 * This code is mainly show
 * the use of execlp
 */ 
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
    printf("Using *execlp* exec ls -l ...\n");
    /**
     * execlp using filename, argument list, and
     * origina ENV to execute the program. 
     */ 
    execlp("ls", "ls", "-l", NULL);
    printf("Program Terminated.\n");
    return 0;
}
