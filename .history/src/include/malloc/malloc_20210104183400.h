#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>
#define MAX_MEMORY_BLOCK_SIZE 4096
struct mem_block
{
    //Size allocated
    size_t *size;
    //Free space left
    int free;
    //Next block
    struct mem_block *next;
};

//Memory allocator
void *malloc(size_t size);
#endif