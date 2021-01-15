#ifndef MALLOC_H
#define MALLOC_H
#include <stddef.h>
struct memory_block
{
    int block_index;
    size_t size;
    void* item;
    struct memory_block* next_block;
};

#endif