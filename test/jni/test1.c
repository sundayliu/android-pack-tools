#include <stdio.h>
int my_thumb(int dummy)
{
    __asm__(
    "mov r0,#1;"
    "mov r1,#2;"
    "add r0,r0,r1;"
    "bx lr"
    );
}

int my_thumb2(int dummy)
{
    __asm__(
    "MOV R0,#0x1;"
    "LDR R0,__start;"
    "ADR R0,__start;"
    "LDR R0,=__start;"
    "__start:;"
    "nop;"
    );
}

int main()
{
    int n = my_thumb(12);
    printf("result:%08x\n", n);
    
    n = my_thumb2(12);
     printf("result:%08x\n", n);
    return 0;
}