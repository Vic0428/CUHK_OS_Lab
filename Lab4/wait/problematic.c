/**
 * This code is intended to show
 * a typical problem when print
 * somethind in child
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    printf("Befor fork...\n");
    if(fork() == 0) {
        printf("Hello, world!\n");
        exit(0);
    }
    printf("After fork...\n");
    return 0;
}