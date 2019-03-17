/**
 * This code is intended to
 * show the use of pipe() with
 * fork()
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    int pipefds[2];
    pid_t pid;
    char buf[30];
    memset(buf, 0, 30);
    /* Create a pipe */
    if(pipe(pipefds) == -1) {
        perror("Pipe");
        return EXIT_FAILURE;
    }
    pid = fork();
    if(pid > 0) {
        printf("Parent write\n");
        /* Parent close the read end */
        close(pipefds[0]);
        /* Parent write in the pipe */
        write(pipefds[1], "CSCI3150", 9);
        /* After finish writing, close the write end */
        close(pipefds[1]);
        wait(NULL);
        printf("Parent finish");
    }
    else {
        printf("Child process begins\n");
        /* Close the wirte end */
        close(pipefds[1]);
        while(read(pipefds[0], buf, 1) == 1)  {
            printf("Child process read: %s\n", buf);
        }
        /* Close the read end */
        close(pipefds[0]);
        printf("Childrent process ends\n");
    }
}