#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>
#define MAX_MEMORY_BLOCK_SIZE 4096
struct mem_block
{
    int index;
    struct mem_block *prev;
    struct mem_block *next;
    void *item;
};
mem_block *block_pages[MAX_MEMORY_BLOCK_SIZE];
void *malloc(size_t size);
#endif