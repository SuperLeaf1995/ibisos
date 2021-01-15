#ifndef MALLOC_H
#define MALLOC_H

struct mem_block
{
    int index;
    struct mem_block *prev;
    struct mem_block *next;
    void *item;
};

#endif