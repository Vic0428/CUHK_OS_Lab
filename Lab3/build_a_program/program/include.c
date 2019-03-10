/**
 * This code is intended to
 * show the power of pre-processor.
 * The pre-processor will expand the
 * #include "header.h"
 */
#include "header.h" 
int main() {
    /**
     * Use gcc -E include.c to show
     * the power of pre-processor
     */  
    add_fun(1, 2);
    return 0;
}