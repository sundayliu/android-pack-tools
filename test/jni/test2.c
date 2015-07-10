int add(int a, int b)
{
    return a + b;
}

 void __attribute__((naked)) __attribute__((noinline)) test_branch_instructions()
{
    __asm__ __volatile(
    "__start1:;"
    "B __start1;"
    );
}