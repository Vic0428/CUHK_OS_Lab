/**
 * This code is intended to handle
 * the error when using execl command
 */ 
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char** argv) {
    printf("Try to exec lss\n");
    execl("/bin/lss", "lls", NULL);
    printf("execl returned! errno is [%d]\n", errno);
    perror("The error message is: ");
    return 0;
}