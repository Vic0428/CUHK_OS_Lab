/**
 * This code takes three commands as
 * input and achieve the result of
 * command 1 | command 2 | command 3
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char** argv) {
    /* Error Usage */
    if(argc != 4) {
        fprintf(stderr, "Usage: <command1> <command 2> <commad 3> ");
        return EXIT_FAILURE;
    }
    /* Store the status of process */
    int status = 0;
    /* Tow pipes */
    int pipefd1[2];
    int pipefd2[2];
    /* In case create pipe failed */
    if(pipe(pipefd1) < 0 || pipe(pipefd2) < 0) {
        perror("Pipe: ");
        return EXIT_FAILURE;
    }
    int pid1;
    int pid2;
    int pid3;
    /* Create the first child process */
    if((pid1 = fork()) == 0) {
        close(pipefd2[1]);
        close(pipefd2[0]);
        close(pipefd1[0]);
        dup2(pipefd1[1], STDOUT_FILENO);
        close(pipefd1[1]);
        execlp(argv[1], argv[1], NULL); 
    }
    else {
        /* Create the second child process */
        if((pid2 = fork()) == 0) {
            close(pipefd1[1]);
            close(pipefd2[0]);
            dup2(pipefd1[0], STDIN_FILENO);
            dup2(pipefd2[1], STDOUT_FILENO);
            close(pipefd1[0]);
            close(pipefd2[1]);
            execlp(argv[2], argv[2], NULL);
        } 
        else {
                /* Create a third child process */
                if((pid3 = fork()) == 0) {
                    close(pipefd1[1]);
                    close(pipefd1[0]);
                    close(pipefd2[1]);
                    dup2(pipefd2[0], STDIN_FILENO);
                    close(pipefd2[0]);
                    execlp(argv[3], argv[3], NULL);
                }
                else {
                    /* Close all pipes */
                    close(pipefd1[0]);
                    close(pipefd1[1]);
                    close(pipefd2[0]);
                    close(pipefd2[1]);
                    /* Wait for all child processes */
                    waitpid(pid1, &status, WUNTRACED);
                    waitpid(pid2, &status, WUNTRACED);
                    waitpid(pid3, &status, WUNTRACED);
                }   
        }
    }

    return 0;
}
/**
 * Reference
 * WUNTRACED: https://stackoverflow.com/questions/33508997/waitpid-wnohang-wuntraced-how-do-i-use-these
 */ 