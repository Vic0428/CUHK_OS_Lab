/**
 * This is the code 
 * for process 2. 
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <semaphore.h>
int main() {
    char *my_sem = "mutex";
    int value = 1;
    sem_t *mutex = sem_open(my_sem, O_CREAT, 0666, value);
    sem_wait(mutex);
    char *str = "This is code with fwq";
    char *ptr = str;
    setbuf(stderr, NULL);
    while(*ptr != '\0') {
        fputc(*ptr, stderr);
        sleep(rand()%2 + 1);
        ptr++;
    }
    sem_post(mutex);
    sem_close(mutex);
    sem_unlink(my_sem);
    return 0;
}
/**
 * Reference:
 * fputs: https://www.tutorialspoint.com/c_standard_library/c_function_fputs.htm
 */ 