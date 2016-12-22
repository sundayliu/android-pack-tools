#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <errno.h>

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

void save_dump(soinfo* si)
{
    const char* dump_name = "/data/local/tmp/dump.so";
    FILE* fp = fopen(dump_name, "wb");
    if (fp != NULL)
    {
        uint32_t base = si->base;
        uint32_t size = si->size;
        uint32_t i = 0;
        for (i = 0; i < size; i+=4096)
        {
            uint32_t start = base + i;
            uint32_t end = start + 4096;
            if (i+4096 > size)
            {
                end = start + (size - i);
            }
            
            uint32_t len = i+4096 > size ? (size - i) : 4096;
            printf("(%08x,%u)\n", start, len);
            fwrite((const void*)start, 1, len, fp);
        }
        fclose(fp);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Invalid param!\n");
        return -1;
    }
    
    char* so_path = argv[1];
    printf("so path:%s\n", so_path);
    void* handle = dlopen(so_path, RTLD_NOW);
    if (handle != NULL)
    {
        print_soinfo((soinfo*)handle);
        save_dump((soinfo*)handle);
        dlclose(handle);
    }
    else
    {
        printf("dlopen %s fail:%s!\n", so_path, strerror(errno));
    }
    return 0;
}