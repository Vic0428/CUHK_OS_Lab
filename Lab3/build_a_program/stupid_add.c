/**
 * This code is intended to 
 * show the power of optimizer
 */
int main() {
    /** 
     * Trying following commands: 
     * gcc -s stupid_add.c -O0 -o add_O0.s
     * gcc -s stupid_add.c -O1 -o add_O1.s
     */ 
    int a = 1;
    a = a + 1;
    a = a + 1;
    return 0;
}