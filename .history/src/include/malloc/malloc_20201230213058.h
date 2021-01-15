#ifndef MALLOC_H
#define MALLOC_H
#define MAX_MEMORY_SIZE 4096
#include <stddef.h>
typedef struct memory_block
{
    int index;
    memory_block* next_block;
    memory_block* previous_block;
};

void *malloc(size_t size);
memory_block *memory_blocks[MAX_MEMORY_SIZE];
int max_page_size = 4096;
#endif