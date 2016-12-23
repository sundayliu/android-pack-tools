#include "3rdparty/lss/linux_syscall_support.h"
#include <stdio.h>
#include <stdlib.h>

void test_tp()
{
    sys_exit_group(1);
    printf("Hello,World");
}