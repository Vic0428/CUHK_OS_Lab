/**
 * This code is intended to show
 * the result of execl.
 */ 
#include <stdio.h>
#include <unistd.h>
int main() {
    printf("Using *execl* to exec ls -l...\n");
    execl("/bin/ls","ls", "-l", NULL);
    /** 
     * After this step, the code of the process is 
     * changed to the target program and it never 
     * returns to the original code. As the result,
     * the line Program Terminated is not printed.
     */ 
    printf("Program Terminated.\n");
    return 0;
}
/**
 * Reference
 * execl: https://linux.die.net/man/3/execl
 */ 
