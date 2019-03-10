/**
 * This code is intended to
 * show the power of pre-processor
 */

#include <stdio.h>
#define TXT "hello"

int main() {
    printf("%s\n", TXT);
    return 0;
}
/**
 * You can use gcc -E hello.c 
 * to show this effect
 */ 