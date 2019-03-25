/**
 * This code is for 
 * NS_cars using semaphores.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc, char * argv[])
{
    sem_t *NS = sem_open("NS", O_CREAT, 0666, 0);
    sem_t *EW = sem_open("EW", O_CREAT, 0666, 1);
    int i, car=0, loop=3;
    for(i=0;i<loop;i++){
        sem_wait(NS);
        printf("Semaphore: The road from north to south is open\n");
        sleep(1);
        printf("NS-Car: car %d passed\n",car++);
        sem_post(EW);
    }
    printf("NS: Time is up. %d cars passed.\n",car);
    sem_close(NS);
    sem_close(EW);
    sem_unlink("NS");
    sem_unlink("EW");
    return 0;
}