#include <malloc/malloc.h>

void *malloc(size_t size)
{
    //Check if the size exceeds maximum allocatable memory
    if(size > MAX_MEMORY_SIZE)
        //If so, return null
        return NULL;
}