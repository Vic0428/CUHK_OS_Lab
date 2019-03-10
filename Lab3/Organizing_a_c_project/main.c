/**
 * This is main function for
 * this c project. And we need 
 * to include header int_header.h
 */ 
#include <stdio.h>
#include "int_header.h"
int main() {
    printf("3 + 10 = %d\n", add_int(3, 10));
    printf("3 * 10 = %d\n", multi_int(3, 10));
}