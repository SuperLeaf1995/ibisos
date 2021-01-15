#include <malloc/malloc.h>
void *malloc(size_t size)
{
    struct memory_block *curr, *prev;
    void* result;
    if(!(free_blocks->size))
    {
        //Initialize memory
    }
}