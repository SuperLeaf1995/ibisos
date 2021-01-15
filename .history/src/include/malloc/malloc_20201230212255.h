#ifndef MALLOC_H
#define MALLOC_H

typedef memory_block
{
    int index;
    memory_block* next_block;
    memory_block* previous_block;
};

#endif