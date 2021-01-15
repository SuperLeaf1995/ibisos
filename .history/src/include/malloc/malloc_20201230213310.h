#ifndef MALLOC_H
#define MALLOC_H
#define MAX_MEMORY_SIZE 4096
#define MAX_PAGE_SIZE   4096
#include <stddef.h>

typedef struct
{
    int index;
    size_t size;
    void* item;
    memory_block *next_block;
    memory_block *previous_block;
} memory_block;

void *malloc(size_t size);
memory_block *memory_blocks[MAX_MEMORY_SIZE];
#endif