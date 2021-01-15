#include <malloc/malloc.h>

void *malloc(size_t size)
{
    //Check if asked for size is > allocatable memory
    if(size > MAX_ALLOC_MEMORY)
    {
        
    }
}