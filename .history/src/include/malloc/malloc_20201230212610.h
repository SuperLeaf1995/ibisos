#ifndef MALLOC_H
#define MALLOC_H
#define MAX_MEMORY_SIZE 4024
#include <stddef.h>
typedef memory_block
{
    int index;
    memory_block* next_block;
    memory_block* previous_block;
};

void *malloc(size_t size);
struct memory_block *memory_blocks[MAX_MEMORY_SIZE];
#endif