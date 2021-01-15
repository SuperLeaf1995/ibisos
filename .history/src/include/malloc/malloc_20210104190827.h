#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>
#define MAX_MEMORY_BLOCK_SIZE 20000
//Max memory, self explanatory
char max_mem[MAX_MEMORY_BLOCK_SIZE];
struct mem_block
{
    //Size allocated
    size_t size;
    //Free space left
    int free;
    //Next block
    struct mem_block *next;
};
//Our free list
struct mem_block *free_list = (void*) max_mem;

//Initialization for a block of memory
void __malloc_initialize();
//Splits a block
void __malloc_split(struct mem_block *block, size_t size);
//Merges a block
void __malloc_merge();
//Memory allocator
void *malloc(size_t size);
#endif