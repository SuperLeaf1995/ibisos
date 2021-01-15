#ifndef MALLOC_H
#define MALLOC_H
#include <stddef.h>
#define MAX_ALLOC_MEMORY 4096
struct memory_block
{
    int block_index;
    int free_space;
    size_t size;
    void* item;
    struct memory_block* prev_block;
    struct memory_block* next_block;
};

struct memory_block *blocks[MAX_ALLOC_MEMORY];
int block_count = 0;
extern "C" void *malloc(size_t size);
#endif