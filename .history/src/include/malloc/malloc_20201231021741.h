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
    } freelist = {{&freelist, 0}}, *freep = &freelist;
#else
    extern "C" void* malloc(unsigned nbytes);
    extern "C" void free(void *ptr);
#endif
#endif