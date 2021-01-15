#ifndef MALLOC_H
#define MALLOC_H
#include <stddef.h>
#define MAX_BLOCK_SIZE 4096
struct memory_block
{
    size_t size;
    int free;
    struct memory_block *next;
};
#endif