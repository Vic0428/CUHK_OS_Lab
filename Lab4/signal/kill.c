/**
 * This code is intended to
 * show the function of kill.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char** argv) {
    printf("My PID: %d\n", getpid());
    sleep(5);
    kill(getpid(), SIGSEGV);
    return 0;
}
/**
 * Reference
 * status code: https://www.codechef.com/wiki/status-codes
 * kill: https://linux.die.net/man/3/kill
 */ 