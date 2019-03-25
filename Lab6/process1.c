/**
 * This is the code 
 * for process 1. 
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
int main() {
    char *str = "This is code with fwq";
    char *ptr = str;
    setbuf(stderr, NULL);
    while(*ptr != '\0') {
        fputc(*ptr, stderr);
        sleep(1);
        ptr++;
    }
    return 0;
}
/**
 * Reference:
 * fputs: https://www.tutorialspoint.com/c_standard_library/c_function_fputs.htm
 */ 