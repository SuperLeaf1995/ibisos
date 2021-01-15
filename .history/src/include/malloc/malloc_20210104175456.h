#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>

struct mem_block
{
    int index;
    struct mem_block *prev;
    struct mem_block *next;
    void *item;
};

void *malloc(size_t size)
{
    
}
#endif