#include <malloc/malloc.h>

void *malloc(size_t size)
{
    //Check if asked for size is > allocatable memory
    if(size > MAX_ALLOC_MEMORY)
    {
        //Reduce block count by 1
        block_count = block_count - 1;
        //Replace last block with a new one
    }
}