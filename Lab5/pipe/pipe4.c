/**
 * This code is to connect command 1 and
 * command 2 and achieve the effect of 
 * command 1 | command 2.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char **argv) {
    int pipefd[2];
    int status;
    if(argc != 3) {
        fprintf(stderr, "Usage: ./pipe4 <command 1> <command 2>");
        return EXIT_FAILURE;
    }
    /* If create pipe failed ... */
    if(pipe(pipefd) < 0) {
        perror("pipe: ");
        return EXIT_FAILURE;
    }
    pid_t pid;
    pid_t pid1;
    /* If create child process failed */
    if((pid = fork()) < 0) {
        perror("fork: ");
        return EXIT_FAILURE;
    }
    /* For the child process */
    if(pid == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        execlp(argv[2], argv[2], NULL);
        close(pipefd[0]);
    }
    /* For the parent process */
    else {
        pid1 = fork();
        /* Create another child process to exec ls */
        if(pid1 == 0) {
            close(pipefd[0]);
            dup2(pipefd[1], STDOUT_FILENO);
            execlp(argv[1], argv[1], NULL);
            close(pipefd[1]);
        }
    }
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid, &status, WUNTRACED);
    waitpid(pid1, &status, WUNTRACED);
    return 0;
}