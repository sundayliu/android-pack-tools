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

static int add(int a, int b)
{
    int sum;
    __asm__(
    "ADD %[s],%[a],%[b];"
    : [s] "=r" (sum)
    : [a] "r" (a), [b] "r" (b)
    );
    return sum;
}

void test_branch_instructions()
{
    __asm__(
    "__start1:;"
    "B __start1;"
    );
}

int main()
{
    int n = my_thumb(12);
    printf("result:%08x\n", n);
    
    n = my_thumb2(12);
     printf("result:%08x\n", n);
     
     n = add(12,144);
     printf("result:%08x\n", n);
     
     test_branch_instructions();
    return 0;
}