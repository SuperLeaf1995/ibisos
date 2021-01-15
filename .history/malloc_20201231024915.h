#ifndef MALLOC_H
#define MALLOC_H
struct memory_block
{
    int index;
    size_t size;
    void *item;
    struct memory_block* previous;
    struct memory_block* next;
};
#endif