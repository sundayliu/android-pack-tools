#include "3rdparty/lss/linux_syscall_support.h"
#include <stdio.h>
#include <stdlib.h>

void test_tp()
{
    sys_exit_group(1);
    #if defined(__arm__)
    __asm__ __volatile__(
        "add R0,R2,#1 \n"
        "BX LR \n"
    );
    #endif
    printf("Hello,World");
}