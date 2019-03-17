/**
 * This code is intended to show
 * how to use pipe to build the
 * like command ls | less
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    int pipefd[2];
    int status;
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
        execlp("less", "less", NULL);
        close(pipefd[0]);
    }
    /* For the parent process */
    else {
        pid1 = fork();
        /* Create another child process to exec ls */
        if(pid1 == 0) {
            close(pipefd[0]);
            dup2(pipefd[1], STDOUT_FILENO);
            execlp("ls", "ls", NULL);
            close(pipefd[1]);
        }
    }
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid, &status, WUNTRACED);
    waitpid(pid1, &status, WUNTRACED);
    return 0;
}