#ifndef MALLOC_H
#define MALLOC_H
#include <stddef.h>
typedef memory_block
{
    int block_index;
    size_t size;
    void* item;
}

#endif