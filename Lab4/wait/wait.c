/**
 * This code is intened to
 * show the command of
 * wait.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char** argv) {
    while(1) {
        printf("Please Enter to execute ls");
        while(getchar() != '\n');
        if(!fork()) {
            execl("/bin/ls", "ls", NULL);
        }
        else {
            wait(NULL);
        }
    }
}
