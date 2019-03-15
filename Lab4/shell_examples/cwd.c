/**
 * Print the current working directory
 */ 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/* Needed by PATH MAX */
#include <limits.h>
/* Needed by getcwd() */
int main() {
    char cwd[PATH_MAX + 1];
    if(getcwd(cwd, PATH_MAX + 1) != NULL) {
        printf("Current working directory: %s", cwd);
    }
    else {
        printf("Error occured\n");
    }
    return 0;
}
/**
 * Reference:
 * getcwd(): http://man7.org/linux/man-pages/man2/getcwd.2.html
 */ 