#ifndef MALLOC_H
#define MALLOC_H
#include <stddef.h>

typedef struct memory_block
{
    int index;
    size_t size;
};

#endif