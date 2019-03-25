#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
int main(int argc, char * argv[])
{
    sem_t *EW = sem_open("EW", O_CREAT, 0666, 1);
    sem_t *NS = sem_open("NS", O_CREAT, 0666, 0);
    int i,car=0, loop=3;
    for(i=0;i<loop;i++){
        sem_wait(EW);
        printf("Semaphore: The road from east to west is open\n");
        sleep(rand()%2+1);
        printf("EW-Car: car %d passed\n",car++);
        sem_post(NS);
    }
    printf("EW: Time is up. %d cars passed.\n",car);
    sem_close(EW);
    sem_close(NS);
    sem_unlink("EW");
    sem_unlink("NS");
    return 0;
}