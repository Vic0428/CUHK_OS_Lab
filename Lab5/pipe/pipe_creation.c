/**
 * This code is intended to
 * show the use of pipe() to 
 * create an actual pipe.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 30
int main() {
    int pipefds[2];
    char buf[BUFF_SIZE];
    /* Create a pipe */
    if(pipe(pipefds) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }
    /* Write to a pipe */
    printf("writing to file descriptor#%d\n", pipefds[1]);
    write(pipefds[1], "CSCI3150", 9);
    /* Read from the pipe */
    printf("Reading from file descriptor#%d\n", pipefds[0]);
    read(pipefds[0], buf, BUFF_SIZE);
    printf("Read %s \n", buf);
    return 0;
}
/**
 * Reference
 * pipe(2): http://man7.org/linux/man-pages/man2/pipe.2.html
 */ 