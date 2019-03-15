/**
 * Change the current working directory. 
 */ 
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#define INPUT_SIZE 255
int main(int argc, char **argv) {
    char buf[PATH_MAX + 1];
    char input[INPUT_SIZE];
    /* Get the current working directory */
    if(getcwd(buf, PATH_MAX + 1) != NULL) {
        printf("Now it is %s\n", buf);
        printf("Where do you want to go?: ");
        fgets(input, INPUT_SIZE, stdin);
        input[strlen(input) - 1] = '\0';
        /* Change the current working directory */
        if(chdir(input) != -1) {
            getcwd(buf, PATH_MAX + 1);
            printf("Now it is %s\n", buf);
        }
        else {
            printf("Can't change directory!\n");
        }

    }

}