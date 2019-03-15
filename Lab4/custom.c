/**
 * Define your custom signal handler
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig) {
    printf("Signal %d Received. Kill me if you can\n", sig);
}
int main() {
    signal(SIGINT, handler);
    printf("Put into while 1 loop\n");
    while(1) {}
    printf("OK\n");
    return 0;
}