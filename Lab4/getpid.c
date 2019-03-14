/**
 * Retrive the PID of the current process
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    /* Retrive the process ID */
    printf("My PID is %d\n", getpid());
}