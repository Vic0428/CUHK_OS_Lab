/**
 * This code is intended to
 * macro can be expanded by
 * the power of pre-processor
 */
#include <stdio.h>
#define SWAP(a, b) { int c; c = a; a = b; b = c;} 

int main() {
    int a = 1;
    int b = 2;
    /* Use gcc -E swap.c to the effect */
    SWAP(a, b);
}