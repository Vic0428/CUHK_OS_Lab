/**
 * Show the result of the following output 
 */ 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    printf("A\n");
    fork();
    printf("B\n");
    fork();
    printf("C\n");
}
