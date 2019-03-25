/**
 * This code is intended to show
 * semaphore in posix system. 
 */ 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/stat.h>

int main() {
    /* The name of semaphore */
    char *my_semaphore = "Vic_semaphore";
    sem_t* my_sem;
    /* The value of my semaphore */
    int value = 2;
    my_sem = sem_open(my_semaphore, O_CREAT, 0666, value);
    /* Wait on semaphore my_sem and decrease it by 1 */
    sem_wait(my_sem);
    printf("My_sem has been decreased by 1\n");
    /* Add semaphore by 1 */
    sem_post(my_sem);
    printf("My_sem has been increased by 1\n");
    /* Close and unlink the semaphore */
    sem_close(my_sem);
    sem_unlink(my_semaphore);
}
