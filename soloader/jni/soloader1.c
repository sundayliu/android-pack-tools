#include <stdio.h>
#include <dlfcn.h>
#include <stdint.h>
typedef int (*pfn_main)(int,char**);

typedef uint32_t Elf32_Addr;
typedef uint32_t Elf32_Word;
typedef uint32_t Elf32_Off;
typedef int32_t Elf32_Sword;
typedef uint16_t Elf32_Half;

typedef struct
{
    Elf32_Word p_type;
    Elf32_Off    p_offset;
    Elf32_Addr  p_vaddr;
    Elf32_Word p_filesz;
    Elf32_Word p_memsz;
    Elf32_Word p_flags;
    Elf32_Word p_align;
}Elf32_Phdr;


#define SOINFO_NAME_LEN 128
typedef struct
{
    char name[SOINFO_NAME_LEN];
    const Elf32_Phdr* phdr;
    size_t phnum;
    Elf32_Addr entry;
    Elf32_Addr base;
    unsigned size;
}soinfo;

void print_soinfo(soinfo* si)
{
    printf("name:%s\n", si->name);
    const Elf32_Phdr* phdr = si->phdr;
    size_t phnum = si->phnum;
    size_t i = 0;
    printf("===program header\n");
    printf("type      offset    vaddr     filesz    memsz     flags     align\n");
    printf("----------------------------------------------------------------------\n");
    for (i = 0; i < phnum; i++)
    {
        printf("%08x  %08x  %08x  %08x  %08x  %08x  %08x\n", 
        phdr->p_type,
        phdr->p_offset,
        phdr->p_vaddr,
        phdr->p_filesz,
        phdr->p_memsz,
        phdr->p_flags,
        phdr->p_align
        );
        phdr++;
    }
    
    printf("entry:%08x\n", si->entry);
    printf("base:%08x\n", si->base);
    printf("size:%08x\n", si->size);
}

int main(int argc, char* argv[])
{
    void* handle = NULL;
    
    handle = dlopen("/data/local/tmp/libexec.so", 0);
    printf("soinfo:%p\n", handle);
    if (handle != NULL)
    {
        print_soinfo((soinfo*)handle);
    }
    return 0;
}