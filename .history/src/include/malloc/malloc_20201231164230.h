#ifndef MALLOC_H
#define MALLOC_H
#include <stddef.h>

typedef struct memory_block
{
    int index;
    int free;
    size_t size;
    void* item;
};

#endif