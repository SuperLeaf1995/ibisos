#include <malloc/malloc.h>

void *malloc(size_t size)
{
    //Check if asked for size is > allocatable memory
    if(size > MAX_ALLOC_MEMORY)
    {
        //Erase last allocated item
        blocks[block_count - 1] = NULL;
    }
}