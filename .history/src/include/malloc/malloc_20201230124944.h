#ifndef MALLOC_H
#define MALLOC_H
#define BLOCK 1024
#include <sbrk/sbrk.h>
#ifdef MALLOC_C
union header
{
    struct
    {
        union header *link;
        unsigned size;
    } s;
    struct
    {
        double d;
        unsigned u;
        void (*i) (void);
    } x;
} free_list = {{&free_list, 0}}, &free_ptr = &free_list;