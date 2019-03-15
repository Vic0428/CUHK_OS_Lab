/**
 * This code is to show the command of
 * sleep()
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    printf("Befor fork!\n");
    /* In the case of child process */
    if(fork() == 0) {
        printf("Hello, world\n");
        exit(0);
    }
    /* Sleep for one second */
    sleep(1);
    printf("After fork...\n");
    return 0;
}