/**
 * This code is a simulation
 * of mum. 
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
    char *filename = "frige.txt";
    printf("Mom comes to home\n");
    printf("Mom checks the frige\n");
    /* Open the file */
    int fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 0777);
    if(fd < 0) {
        perror("open file failed\n");
        return EXIT_FAILURE;
    }
    if(lseek(fd, 0, SEEK_END) == 0) {
        printf("The frige has no milk\n");
        printf("Mom goes to the supermarket to buy milk\n");
        sleep(2);
        write(fd, "milk ", 5);
        printf("Mom has put milk into the frige\n");
        if(lseek(fd, 0, SEEK_END) > 5) {
            printf("What a waste of food!\n");
        }
    }
    else {
        printf("Mom close the frige and there are one milk\n");
    }
    return 0;

}
/**
 * Reference:
 * lseek(): http://man7.org/linux/man-pages/man2/lseek.2.html
 */ 