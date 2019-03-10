# Organizing a C Project
File architecture
    
    - int_header.h
    - main.c
    - add_int.c
    - multi_int.c

In all three c files, we need to include *int_header.h*. 

We need to compile three files in to object code seperately. 

gcc -c main.c

gcc -c add_int.c

gcc -c multi_int.c

Finally, we need to use linker to combine there three object code. 

gcc main.o -o main