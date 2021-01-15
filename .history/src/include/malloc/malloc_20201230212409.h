#ifndef MALLOC_H
#define MALLOC_H
#define MAX_MEMORY_SIZE 4024
typedef memory_block
{
    int index;
    memory_block* next_block;
    memory_block* previous_block;
};

#endif