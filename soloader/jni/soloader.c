#include <stdio.h>
#include <dlfcn.h>
typedef int (*pfn_main)(int,char**);

int main(int argc, char* argv[])
{
    printf("hello\n");
    const char* so_path = "/data/local/tmp/xxx.so";
    void* handle = NULL;
    void* pfn = NULL;
    if (argc == 2)
    {
        so_path = argv[1];
    }
    
    printf("so path:%s\n", so_path);
    handle = dlopen(so_path, RTLD_NOW);
    
    printf("result:%p\n", handle);
    if (handle == 0)
    {
        perror("file not found!");
        return -1;
    }
    
    pfn = dlsym(handle,"main");
    if (pfn != NULL)
    {
        ((pfn_main)pfn)(argc, argv);
    }
    
    dlclose(handle);
    return 0;
}