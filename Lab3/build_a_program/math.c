/** 
 * If I try to compile a normal way gcc math.c, 
 * it will show you the error. Undefined refence
 * to 'sin' function.
 */
int main(int argc, char** argv) {
    float v = 3.14;
    printf("sin(3.14) is %f\n", v);
    return 0;
}
/**
 * You could provide -lm option to 
 * gcc to link the math library. 
 * gcc math.c -lm.
 * And you can use ldd a.out to find
 * the dynamically linked library. 
 */ 