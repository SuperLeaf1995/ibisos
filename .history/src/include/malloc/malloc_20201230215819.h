#ifndef MALLOC_H
#define MALLOC_H
#include <stddef.h>
#define MAX_BLOCK_SIZE 4096
struct memory_block
{
    size_t size;
    int free;
    struct memory_block *prev;
    struct memory_block *next;
};

struct memory_block* memory[MAX_BLOCK_SIZE];
struct memory_block* free_blocks = (memory_block*) memory;
void *malloc(size_t size);
#endif